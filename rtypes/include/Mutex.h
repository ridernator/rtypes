#pragma once

#include <pthread.h>

namespace rtypes {

    class Mutex {
    public:
        void enter();
        void leave();
    private:
        pthread_mutex_t mutex;
    };
}