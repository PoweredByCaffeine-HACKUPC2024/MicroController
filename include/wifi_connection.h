#include <WiFi.h>
#include <map>
#include <string>
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

    void static handleClient(WiFiClient client);

    static WiFiServer startServer(int port);
};