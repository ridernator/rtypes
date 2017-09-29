#include "Semaphore.h"

namespace rtypes {

    Semaphore::Semaphore(const uint32_t initialCount) : currentCount(initialCount) {
    }

    void Semaphore::enter() {
        if (currentCount <= 1) {
            mutex.lock();
        }

        --currentCount;
    }

    void Semaphore::leave() {
        ++currentCount;
        
        mutex.unlock();
    }

    uint32_t Semaphore::getCurrentCount() {
        return currentCount;
    }
}