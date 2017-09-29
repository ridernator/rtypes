#include "PeriodicCaller.h"

namespace rtypes {

    PeriodicCaller::PeriodicCaller(const uint64_t period) : period(period),
    isRunning(false),
    shouldDie(false) {
        pthread_cond_init(&condition, NULL);

        start(true);
    }

    PeriodicCaller::~PeriodicCaller() {
        isRunning = false;
        shouldDie = true;

        pthread_cond_signal(&condition);
    }

    void PeriodicCaller::addTask(Task* task) {
        tasksMutex.enter();

        tasks.push_back(task);

        tasksMutex.leave();
    }

    void PeriodicCaller::removeTask(const Task* task) {
        tasksMutex.enter();

        for (std::vector<Task*>::iterator iterator = tasks.begin(); iterator != tasks.end(); ++iterator) {
            if (*iterator == task) {
                tasks.erase(iterator);

                break;
            }
        }

        tasksMutex.leave();
    }

    void PeriodicCaller::go() {
        if (!isRunning) {
            isRunning = true;

            pthread_cond_signal(&condition);
        }
    }

    void PeriodicCaller::stop() {
        isRunning = false;
    }

    void PeriodicCaller::run() {
        pthread_mutex_t mutex;
        pthread_mutex_init(&mutex, NULL);
        pthread_mutex_lock(&mutex);

        struct timespec sleepUntil;
        clock_gettime(CLOCK_REALTIME, &sleepUntil);

        while (!shouldDie) {
            sleepUntil.tv_sec += period / 1000;
            sleepUntil.tv_nsec += 1000000 * (period % 1000);
            if (sleepUntil.tv_nsec >= 1000000000) {
                sleepUntil.tv_sec = sleepUntil.tv_nsec % 1000000000;
                ++sleepUntil.tv_sec;
            }

            if (pthread_cond_timedwait(&condition, &mutex, &sleepUntil) == 0) {
                clock_gettime(CLOCK_REALTIME, &sleepUntil);
            } else {
                if (isRunning) {
                    tasksMutex.enter();
                    
                    for (std::vector<Task*>::iterator iterator = tasks.begin(); iterator != tasks.end(); ++iterator) {
                        (*iterator)->performTask();
                    }
                    
                    tasksMutex.leave();
                }
            }
        }
    }
}