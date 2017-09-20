#include "Mutex.h"

namespace rtypes {

    void Mutex::enter() {
        pthread_mutex_lock(&mutex);
    }

    void Mutex::leave() {
        pthread_mutex_unlock(&mutex);
    }
}