#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>

/*
Represents a single log entry.
This is the data that will be produced by producer threads
and consumed by consumer threads.
*/

struct LogEntry
{
    int id;                 // unique log id
    std::string message;    // log message
};

#endif
