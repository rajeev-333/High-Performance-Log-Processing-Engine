#include "MutexQueue.h"

void MutexQueue::push(const LogEntry& log)
{
    std::lock_guard<std::mutex> lock(mtx);

    queue.push(log);
}

bool MutexQueue::pop(LogEntry& log)
{
    std::lock_guard<std::mutex> lock(mtx);

    if(queue.empty())
        return false;

    log = queue.front();

    queue.pop();

    return true;
}
