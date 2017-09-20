#include <mutex>

#include "Semaphore.h"

namespace rtypes {

    Semaphore::Semaphore() : count(1) {

    }

    Semaphore::Semaphore(const uint32_t initialCount) : count(initialCount) {
    }

    void Semaphore::enter() {
        if (count <= 1) {
            mutex.lock();
        }

        --count;
    }

    void Semaphore::leave() {
        ++count;
        mutex.unlock();
    }
    
    uint32_t Semaphore::getCurrentCount() {
        return count;
    }
}