#ifndef LOGCONSUMER_H
#define LOGCONSUMER_H

#include "IQueue.h"

/*
Consumer reads logs from queue and processes them.
Runs inside consumer threads.
*/

class LogConsumer
{
private:

    IQueue* queue;

public:

    LogConsumer(IQueue* q);

    void consume(int count);
};

#endif
