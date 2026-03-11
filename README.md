# High-Performance Log Processing Engine

A **high-performance log processing engine implemented in modern C++** that demonstrates **multi-threading, concurrency control, and memory-efficient queue design**.

This project compares **mutex-based synchronization** with a **lock-free queue implementation** to evaluate their performance in a producer–consumer log processing pipeline.

The system simulates a **high-throughput logging environment** where multiple threads generate logs and worker threads process them concurrently.

---

# Key Features

* Multi-threaded **producer–consumer architecture**
* Lock-free queue implementation using atomic operations
* Mutex-based thread-safe queue implementation
* Performance benchmarking and comparison
* Modular **object-oriented C++ design**
* Demonstrates **concurrency control and memory management concepts**
---

# Project Architecture

The system follows a **producer–consumer pipeline architecture**.

```
Producers (Threads)
        │
        ▼
   Queue Layer
 ┌───────────────┐
 │ Mutex Queue   │
 │ Lock-Free     │
 └───────────────┘
        │
        ▼
Consumers (Threads)
        │
        ▼
 Log Processing Engine
```

### Workflow

1. Producer threads generate log entries.
2. Logs are pushed into a shared queue.
3. Consumer threads retrieve logs concurrently.
4. Benchmark module measures processing time.
5. Results compare mutex vs lock-free performance.

---

# Project Structure

```
High-Performance-Log-Processing-Engine
│
├── README.md
│
├── include
│   ├── LogEntry.h
│   ├── IQueue.h
│   ├── MutexQueue.h
│   ├── LockFreeQueue.h
│   ├── LogProducer.h
│   ├── LogConsumer.h
│   └── Benchmark.h
│
└── src
    ├── main.cpp
    ├── MutexQueue.cpp
    ├── LockFreeQueue.cpp
    ├── LogProducer.cpp
    ├── LogConsumer.cpp
    └── Benchmark.cpp
```

### Directory Overview

| Folder      | Description                                                             |
| ----------- | ----------------------------------------------------------------------- |
| `include/`  | Header files defining system interfaces and classes                     |
| `src/`      | Implementation of queue structures, producers, consumers, and benchmark |
| `README.md` | Documentation and project overview                                      |

---

# Technologies Used

• **C++17**
• **Multithreading (std::thread)**
• **Mutex synchronization**
• **Lock-free programming using std::atomic**
• **High-resolution performance benchmarking**

---

# Concurrency Design

The engine evaluates two concurrency control strategies.

### Mutex-Based Queue

Uses **mutual exclusion locks** to ensure safe access to the queue.

Advantages:

• Simple implementation
• Easy to reason about correctness

Limitations:

• Threads may block waiting for locks
• Increased context switching overhead

---

### Lock-Free Queue

Uses **atomic operations instead of locks**.

Advantages:

• Non-blocking operations
• Reduced thread contention
• Better scalability on multi-core systems

Challenges:

• More complex implementation
• Requires careful memory management

---

# How to Build and Run

### 1. Clone the repository

```
git clone https://github.com/rajeev-333/High-Performance-Log-Processing-Engine.git
```

### 2. Navigate to the project directory

```
cd High-Performance-Log-Processing-Engine
```

### 3. Compile the project

```
g++ -std=c++17 src/*.cpp -Iinclude -pthread -o log_engine
```

### 4. Run the executable

```
./log_engine
```

---

# Example Output

```
Starting benchmark...

Mutex Queue Time: 210 ms
LockFree Queue Time: 130 ms

Logs processed: 100000
```

The benchmark demonstrates how **lock-free structures can outperform traditional mutex-based synchronization under concurrent workloads.**

---

# Concepts Demonstrated

This project demonstrates several **core systems programming concepts**:

• Multi-threaded programming
• Producer–consumer design pattern
• Concurrency control mechanisms
• Lock-free data structures
• Performance benchmarking
• Memory management in concurrent systems

---

# Learning Objectives

This project was designed to explore:

• **How concurrent systems handle shared resources**
• **Performance differences between blocking and non-blocking synchronization**
• **How lock-free algorithms improve scalability**
• **Designing modular concurrent systems in C++**

---

# Possible Future Improvements

• Thread pool implementation
• Multiple producers and consumers
• Real log file ingestion
• Memory pool optimization
• Real-time log analytics
• Performance visualization graphs

---



# License

This project is open-source and available under the **MIT License**.
