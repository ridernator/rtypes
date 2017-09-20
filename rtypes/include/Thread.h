#pragma once

#include <pthread.h>

namespace rtypes {

    class Thread {
    public:
        virtual ~Thread();

        void start();
        
        bool detach();

        bool join();
        
        virtual void run() = 0;

    private:        
        pthread_t thread;
    };
}