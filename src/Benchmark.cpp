#include "Benchmark.h"
#include "MutexQueue.h"
#include "LockFreeQueue.h"
#include "LogProducer.h"
#include "LogConsumer.h"

#include <thread>
#include <vector>
#include <chrono>
#include <iostream>

void Benchmark::run()
{
    const int logs = 100000;

    {
        MutexQueue queue;

        LogProducer producer(&queue);
        LogConsumer consumer(&queue);

        auto start = std::chrono::high_resolution_clock::now();

        std::thread p(&LogProducer::produce, &producer, logs);
        std::thread c(&LogConsumer::consume, &consumer, logs);

        p.join();
        c.join();

        auto end = std::chrono::high_resolution_clock::now();

        std::cout << "Mutex Queue Time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }

    {
        LockFreeQueue queue;

        LogProducer producer(&queue);
        LogConsumer consumer(&queue);

        auto start = std::chrono::high_resolution_clock::now();

        std::thread p(&LogProducer::produce, &producer, logs);
        std::thread c(&LogConsumer::consume, &consumer, logs);

        p.join();
        c.join();

        auto end = std::chrono::high_resolution_clock::now();

        std::cout << "LockFree Queue Time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";
    }
}
