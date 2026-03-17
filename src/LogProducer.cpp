#include "LogProducer.h"

LogProducer::LogProducer(IQueue* q)
{
    queue = q;
}

void LogProducer::produce(int count)
{
    for(int i = 0; i < count; i++)
    {
        LogEntry log;

        log.id = i;

        log.message = "Sample log message";

        queue->push(log);
    }
}
