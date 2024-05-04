#include "config.h"
#include "certificates.h"
#include <PromLokiTransport.h>
#include <PrometheusArduino.h>
#include <list>

class DataSender
{
private:
    PromLokiTransport transport;
    WriteRequest req;
    std::list<TimeSeries> series;
    PromClient client;

public:
    DataSender();
    ~DataSender();

    void startTransport();
    void startClient();
    void addToSeries(TimeSeries ts);
    void setRequest();
    template <typename T>
    void addToSeries(const char *name, T value, const char *labels = "");

    void sendData();
};
