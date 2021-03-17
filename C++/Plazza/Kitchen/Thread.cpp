/*
** EPITECH PROJECT, 2020
** bootstrap_plaza
** File description:
** Thread
*/

#include "Thread.hpp"
#include "../Exception/ThreadException.hpp"

namespace PlazzaProject {

Thread::Thread() : _attr(NULL), _function(NULL), _argv(NULL),  _status(Status::INIT)
{
}

Thread::Thread(const pthread_attr_t *attr, startRoutine function, void *argv) 
    : _attr(attr), _function(function), _argv(argv), _status(Status::INIT)
{
}

Thread::~Thread()
{
    _status = Status::DEAD;
}

void Thread::setFunction(startRoutine function)
{
    if (_status != Status::INIT)
        throw ThreadException("Can't set argv when the thread is on current work");
    _function = function;    
}

void Thread::setArgv(void *argv)
{
    if (_status != Status::INIT)
        throw ThreadException("Can't set argv when the thread is on current work");
    _argv = argv;
}


void Thread::destroy()
{
    _status = Status::DEAD;
    pthread_exit(&_ret);
}

void Thread::start()
{
    _status = Status::START;
    if (pthread_create(&_thread, _attr, _function, _argv) != 0) {
        throw ThreadException("Thread Error : start function");
    }
}

void Thread::join(void **_thread_return)
{
    if (pthread_join(_thread, _thread_return) != 0) {
        throw ThreadException("Thread Error : join function");
    }
}

} // namespace
