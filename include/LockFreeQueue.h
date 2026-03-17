#ifndef LOCKFREEQUEUE_H
#define LOCKFREEQUEUE_H

#include <atomic>
#include "IQueue.h"

/*
CAS-based Lock-Free Queue (Michael & Scott Algorithm - simplified)
*/

class LockFreeQueue : public IQueue
{
private:

    struct Node
    {
        LogEntry data;
        std::atomic<Node*> next;

        Node(const LogEntry& log) : data(log), next(nullptr) {}
    };

    std::atomic<Node*> head;
    std::atomic<Node*> tail;

public:

    LockFreeQueue();

    void push(const LogEntry& log) override;

    bool pop(LogEntry& log) override;
};

#endif
