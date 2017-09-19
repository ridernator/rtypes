#include "Thread.h"

namespace rtypes {
    Thread::~Thread() {
        // Not much to do here
    }
    
    void Thread::start() {
        thread = std::thread(&Thread::run, this);
    }

    bool Thread::join() {
        bool returnVal = true;

        if (thread.joinable()) {
            thread.join();
        } else {
            returnVal = false;
        }

        return returnVal;
    }
}