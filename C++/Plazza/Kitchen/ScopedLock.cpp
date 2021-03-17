/*
** EPITECH PROJECT, 2020
** bootstrap_plaza
** File description:
** ScopedLock
*/

#include "ScopedLock.hpp"

ScopedLock::ScopedLock(Mutex &mutex) : _mutex(mutex)
{
    _mutex.lock();
    std::cout << "Constructor ScopedLock" << std::endl;
}

ScopedLock::~ScopedLock()
{
    std::cout << "Destructor ScopedLock" << std::endl;
    _mutex.unlock();
}
