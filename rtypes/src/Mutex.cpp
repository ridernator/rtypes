#include "Mutex.h"

namespace rtypes {
    Mutex::Mutex() {
        pthread_mutex_init(&mutex, NULL);
    }

    void Mutex::enter() {
        pthread_mutex_lock(&mutex);
    }

    void Mutex::leave() {
        pthread_mutex_unlock(&mutex);
    }

    void Mutex::lock() {
        enter();
    }

    void Mutex::unlock() {
        leave();
    }
}