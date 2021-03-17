/*
** EPITECH PROJECT, 2020
** bootstrap_plaza
** File description:
** Thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <pthread.h>
#include <chrono>
namespace PlazzaProject {
class Thread {
    using startRoutine = void *(*)(void *);
    public:
        Thread();
        Thread(const pthread_attr_t *, startRoutine function, void *argv);
        ~Thread();

        void join(void **__thread_return = NULL);
        void start();
        void destroy();
        void setArgv(void *argv);
        void setFunction(startRoutine function);
        pthread_t const getThread() const { return _thread;};

        enum Status {
            INIT,
            START,
            RUN,
            DEAD
        };

        Status const getStatus() const {return _status;};
    protected:
        pthread_t _thread;
        void *_argv;
        startRoutine _function;
        const pthread_attr_t *_attr;
        std::chrono::time_point<std::chrono::high_resolution_clock> _start;
        int _ret;
        Status _status;
    private:
};

} // namespace

#endif /* !THREAD_HPP_ */
