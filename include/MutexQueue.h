#ifndef MUTEXQUEUE_H
#define MUTEXQUEUE_H

#include <queue>
#include <mutex>
#include "IQueue.h"

/*
Thread-safe queue using mutex lock.
This represents blocking synchronization.
*/

class MutexQueue : public IQueue
{
private:

    std::queue<LogEntry> queue;
    std::mutex mtx;

public:

    void push(const LogEntry& log) override;

    bool pop(LogEntry& log) override;
};

#endif
