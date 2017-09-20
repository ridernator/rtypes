#include "Thread.h"

namespace rtypes {
    void* internalRun(void* instance) {
        ((Thread*)instance)->run();
    }
    
    Thread::~Thread() {
        // Not much to do here
    }
    
    void Thread::start() {
        pthread_create(&thread, NULL, internalRun, this);        
    }

    bool Thread::join() {
        pthread_join(thread, NULL);
//        bool returnVal = true;
//
//        if (thread.joinable()) {
//            thread.join();
//        } else {
//            returnVal = false;
//        }
//
//        return returnVal;
        return true;
    }
}