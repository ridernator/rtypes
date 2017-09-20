#include "Thread.h"

#include <errno.h>

namespace rtypes {

    void* internalRun(void* instance) {
        ((Thread*) instance)->run();
        
        return NULL;
    }

    Thread::~Thread() {
        // Not much to do here
    }

    bool Thread::start(const bool detached) {
        if ((errno = pthread_create(&thread, NULL, internalRun, this)) == 0) {
            if (detached) {
                errno = pthread_detach(thread);
            }
        }

        return errno == 0;
    }

    bool Thread::join() {
        return ((errno = pthread_join(thread, NULL)) == 0);
    }
}