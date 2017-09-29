#pragma once

#include <pthread.h>

namespace rtypes {

    class Mutex {
    public:
        Mutex();
        
        void enter();
        void leave();
        
        void lock();
        void unlock();
    private:
        pthread_mutex_t mutex;
    };
}