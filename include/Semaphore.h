#pragma once

#include <stdint.h>
#include <atomic>
#include <mutex>


namespace rtypes {
    class Semaphore{
    public :
        Semaphore();
        Semaphore(const uint32_t initialCount);
        
        void enter();
        void leave();
        
        uint32_t getCurrentCount();
    private :
        std::atomic_uint32_t count;
        std::mutex mutex;
    };
}