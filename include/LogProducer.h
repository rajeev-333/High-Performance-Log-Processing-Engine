#ifndef LOGPRODUCER_H
#define LOGPRODUCER_H

#include "IQueue.h"

/*
Producer generates logs and pushes them to queue.
Runs inside producer threads.
*/

class LogProducer
{
private:

    IQueue* queue;

public:

    LogProducer(IQueue* q);

    void produce(int count);
};

#endif
