/*
** EPITECH PROJECT, 2020
** bootstrap_plaza
** File description:
** Mutex
*/

#include "Mutex.hpp"
#include "../Exception/MutexException.hpp"

Mutex::Mutex() : _mutex(PTHREAD_MUTEX_INITIALIZER)
{
}

Mutex::~Mutex()
{
}

void Mutex::lock()
{
    if (pthread_mutex_lock(&_mutex) != 0) {
        throw MutexException("Mutex lock exception");
    }
}

void Mutex::unlock()
{
    if (pthread_mutex_unlock(&_mutex) != 0) {
        throw MutexException("Mutex unlock exception");
    }
}

int Mutex::trylock()
{
    return pthread_mutex_trylock(&_mutex);
}