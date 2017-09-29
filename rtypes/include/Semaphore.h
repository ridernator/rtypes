#pragma once

#include "Mutex.h"

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
        Mutex mutex;
    };
}