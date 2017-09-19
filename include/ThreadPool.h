#pragma once

#include <thread>
#include <vector>

#include "Task.h"

namespace rtypes {

    class ThreadPool {
    public:
        ThreadPool(const uint32_t numThreads = 0);
        
        void addTask(Task* task);
        
        void executeTasks();
        
    private :        
        const uint32_t numThreads;
        std::vector<std::thread*> threads;
    };
}