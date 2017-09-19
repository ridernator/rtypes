#pragma once

#include <thread>

namespace rtypes {

    class Thread {
    public:
        virtual ~Thread();

        void start();

        bool join();

    private:
        virtual void run() = 0;
        
        std::thread thread;
    };
}