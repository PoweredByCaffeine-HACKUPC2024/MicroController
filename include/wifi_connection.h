#include <WiFi.h>
#include <map>
#include <string>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <mbedtls/net_sockets.h>
#include <mbedtls/ssl.h>
#include <mbedtls/error.h>
#include "definitions.h"

class WiFiConnection
{

public:
    /**
     * Connect to WiFi with the given credentials
     */
    static void connectToWiFi();

    static void sendRequest(String url, String method, std::map<String, String> headers, String body);
    static void simpleSendRequest(String url, String method, std::map<String, String> headers, String body);

    void static handleClient(WiFiClient client);

    static WiFiServer startServer(int port);
};