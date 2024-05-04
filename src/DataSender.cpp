#include "DataSender.h"

DataSender::DataSender() : req(series.size(), 1024)
{
    // Configure the transport
    transport.setUseTls(true);
    transport.setCerts(grafanaCert, strlen(grafanaCert));
    transport.setWifiSsid(WIFI_SSID);
    transport.setWifiPass(WIFI_PASSWORD);
    transport.setDebug(Serial);

    // Configure the client
    client = PromClient(transport);
    client.setUrl(GC_URL);
    client.setPath((char *)GC_PATH);
    client.setPort(GC_PORT);
    client.setUser(GC_USER);
    client.setPass(GC_PASS);
    client.setDebug(Serial); // Remove this line to disable debug logging of the client.
}

void DataSender::startTransport()
{
    if (!transport.begin())
    {
        Serial.println(transport.errmsg);
        while (true)
        {
        };
    }
}

void DataSender::startClient()
{
    if (!client.begin())
    {
        Serial.println(client.errmsg);
        while (true)
        {
        };
    }
}

void DataSender::addToSeries(TimeSeries ts)
{
    series.push_back(ts);
}

void DataSender::setRequest()
{
    req = WriteRequest(series.size(), 1024);
    for (auto &ts : series)
        req.addTimeSeries(ts);
    req.setDebug(Serial); // Remove this line to disable debug logging of the write request serialization and compression.
}

void DataSender::sendData()
{
    setRequest();
    PromClient::SendResult res = client.send(req);
    if (!res == PromClient::SendResult::SUCCESS)
    {
        Serial.println(client.errmsg);
    }
    for (auto &ts : series)
        ts.resetSamples();
}

template <typename T>
inline void DataSender::addToSeries(const char *name, T value, const char *labels)
{
    for (auto &ts : series)
    {
        if (ts.getName() == name)
        {
            if (!ts.addSample(transport.getTimeMillis(), value))
            {
                Serial.println(ts.errmsg);
            }
            return;
        }
    }
}
