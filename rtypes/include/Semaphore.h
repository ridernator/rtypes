#pragma once

#include <pthread.h>

#include <stdint.h>


namespace rtypes {

    class Semaphore {
    public:
        Semaphore(const uint32_t initialCount = 1);

        void enter();
        void leave();

        uint32_t getCurrentCount();
    private:
        volatile uint32_t currentCount;
        pthread_mutex_t mutex;
    };
}