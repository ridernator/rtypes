#include "ThreadPool.h"

namespace rtypes {

    ThreadPool::ThreadPool(const uint32_t numThreads){// : numThreads(numThreads == 0 ? std::thread::hardware_concurrency() : numThreads) {
        if (numThreads == 0) {
            this->numThreads = std::thread::hardware_concurrency();
        }else{
            this->numThreads = numThreads;
        }
        
        for (uint32_t index = 0; index < numThreads; index++) {
            threads.push_back(new std::thread(&ThreadPool::executeTasks, this));
        }
    }

    void ThreadPool::executeTasks() {

    }

    void ThreadPool::addTask(Task* task) {

    }

}