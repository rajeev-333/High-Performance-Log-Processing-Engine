#include "LogConsumer.h"

LogConsumer::LogConsumer(IQueue* q)
{
    queue = q;
}

void LogConsumer::consume(int count)
{
    int processed = 0;

    LogEntry log;

    while(processed < count)
    {
        if(queue->pop(log))
        {
            processed++;
        }
    }
}
