#pragma once

#include <stdint.h>
#include <fstream>
#include <vector>

#include "Thread.h"
#include "Task.h"
#include "Mutex.h"

namespace rtypes {

    class PeriodicCaller : private Thread {
    public:
        PeriodicCaller(const uint64_t period);
        
        ~PeriodicCaller();

        void addTask(Task* task);

        void removeTask(const Task* task);

        void go();

        void stop();

    private:
        void run();
        
        pthread_cond_t condition;
        const uint64_t period;
        bool isRunning;
        bool shouldDie;
        
        std::vector<Task*> tasks;
        Mutex tasksMutex;
    };
}