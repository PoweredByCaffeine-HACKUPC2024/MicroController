#include "config.h"
#include "certificates.h"
#include <PromLokiTransport.h>
#include <PrometheusArduino.h>
#include <list>

class DataSender
{
private:
    WriteRequest req;
    std::list<TimeSeries *> series;
    PromClient client;
    PromLokiTransport transport;

public:
    DataSender();
    ~DataSender();

    void initialize();
    void startTransport();
    void startClient();
    void addToSeries(TimeSeries *ts);
    void setRequest();
    PromLokiTransport getTransport();

    void addValueToSeries(const char *name, double value, const char *labels = "");

    void sendData();
};
