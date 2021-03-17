/*
** EPITECH PROJECT, 2020
** bootstrap_plaza
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <pthread.h>
#include "IMutex.hpp"

class Mutex : IMutex{
    public:
        Mutex();
        void lock();
        void unlock();
        int trylock();
        ~Mutex();
    protected:
       pthread_mutex_t _mutex;
    private:

};

#endif /* !MUTEX_HPP_ */
