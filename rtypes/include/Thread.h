#pragma once

#include <pthread.h>

namespace rtypes {

    class Thread {
    public:
        virtual ~Thread();

        bool start(const bool detached = false);

        bool join();

        virtual void run() = 0;
    private:
        pthread_t thread;
        pthread_mutex_t mutex;
    };
}