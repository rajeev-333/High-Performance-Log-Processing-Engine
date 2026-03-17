#ifndef IQUEUE_H
#define IQUEUE_H

#include "LogEntry.h"

/*
Interface for queue implementations.

Both MutexQueue and LockFreeQueue
will implement this interface.
*/

class IQueue
{
public:
    virtual void push(const LogEntry& log) = 0;

    virtual bool pop(LogEntry& log) = 0;

    virtual ~IQueue() {}
};

#endif
