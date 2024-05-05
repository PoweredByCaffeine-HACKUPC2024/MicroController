#include "wifi_connection.h"

/**
 * Connects to the WiFi network.
 *
 * @return void
 *
 * @throws None
 */
void WiFiConnection::connectToWiFi()
{
    WiFi.mode(WIFI_STA); // Optional
    Serial.println("\nConnecting to WiFi " + String(SSID) + "...");
    WiFi.begin(SSID, PASSWORD);

    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS)
    {
        delay(1000);
        Serial.print(".");
    }

    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("\nFailed to connect to WiFi.");
    }
    else
    {
        Serial.print("\nConnected to WiFi!\nIP address: ");
        Serial.println(WiFi.localIP());
    }
}

void WiFiConnection::sendRequest(String url, String method, std::map<String, String> headers, String body)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        connectToWiFi();
    }

    WiFiClientSecure client;
    client.setInsecure(); // Enable insecure connections
    client.getPeerCertificate();

    // get baseUrl
    size_t found = url.indexOf("/");
    String baseUrl = url.substring(0, found);

    int port = HTTPS_PORT;
    // Connect to the server
    if (!client.connect(url.c_str(), port))
    {
        Serial.println("Connection failed!");
        return;
    }

    // Add headers to the client
    for (auto const &entry : headers)
    {
        client.print(entry.first + ": " + entry.second + "\r\n");
    }

    // Make the request
    client.print(method + " " + url + " HTTP/1.1\r\n" +
                 "Host: " + baseUrl + "\r\n" +
                 "Content-Length: " + String(body.length()) + "\r\n" +
                 "Connection: close\r\n");

    // Add extra line break before the body
    client.println();

    // Send body
    client.print(body);

    // Read response
    while (client.connected())
    {
        String line = client.readStringUntil('\n');
        Serial.println(line);
    }

    // Disconnect
    client.stop();
}

void WiFiConnection::simpleSendRequest(String url, String method, std::map<String, String> headers, String body)
{
    HTTPClient client;
    client.begin(url);

    // Add headers to the client
    for (auto const &entry : headers)
    {
        client.addHeader(entry.first, entry.second);
    }

    int httpCode = 0;
    if (method == "GET")
    {
        httpCode = client.GET();
    }
    else if (method == "POST")
    {
        httpCode = client.POST(body);
    }
    else
    {
        Serial.println("Invalid method");
        return;
    }

    String response = client.getString();
    Serial.println(response);

    client.end();
}