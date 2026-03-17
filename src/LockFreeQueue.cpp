#include "LockFreeQueue.h"

LockFreeQueue::LockFreeQueue()
{
    Node* dummy = new Node(LogEntry{0, ""});

    head.store(dummy);
    tail.store(dummy);
}

/*
Push using CAS loop
*/
void LockFreeQueue::push(const LogEntry& log)
{
    Node* newNode = new Node(log);

    while(true)
    {
        Node* oldTail = tail.load();
        Node* next = oldTail->next.load();

        // Check if tail is still consistent
        if(oldTail == tail.load())
        {
            // If tail is really the last node
            if(next == nullptr)
            {
                // Try to link new node at the end
                if(oldTail->next.compare_exchange_weak(next, newNode))
                {
                    // Move tail forward
                    tail.compare_exchange_weak(oldTail, newNode);
                    return;
                }
            }
            else
            {
                // Tail is behind, move it forward
                tail.compare_exchange_weak(oldTail, next);
            }
        }
    }
}

/*
Pop using CAS loop
*/
bool LockFreeQueue::pop(LogEntry& log)
{
    while(true)
    {
        Node* oldHead = head.load();
        Node* oldTail = tail.load();
        Node* next = oldHead->next.load();

        // Check consistency
        if(oldHead == head.load())
        {
            // Queue empty
            if(next == nullptr)
                return false;

            // Tail falling behind
            if(oldHead == oldTail)
            {
                tail.compare_exchange_weak(oldTail, next);
            }
            else
            {
                log = next->data;

                // Move head forward
                if(head.compare_exchange_weak(oldHead, next))
                {
                    delete oldHead;
                    return true;
                }
            }
        }
    }
}
