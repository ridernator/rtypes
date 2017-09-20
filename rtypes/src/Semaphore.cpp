#include "Semaphore.h"

namespace rtypes {

    Semaphore::Semaphore(const uint32_t initialCount) : currentCount(initialCount) {
    }

    void Semaphore::enter() {
        if (currentCount <= 1) {
            pthread_mutex_lock(&mutex);
        }

        --currentCount;
    }

    void Semaphore::leave() {
        ++currentCount;
        pthread_mutex_unlock(&mutex);
    }

    uint32_t Semaphore::getCurrentCount() {
        return currentCount;
    }
}