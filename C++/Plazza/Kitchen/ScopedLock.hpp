/*
** EPITECH PROJECT, 2020
** bootstrap_plaza
** File description:
** ScopedLock
*/

#ifndef SCOPEDLOCK_HPP_
#define SCOPEDLOCK_HPP_

#include <iostream>
#include "Mutex.hpp"

class ScopedLock {
    public:
        ScopedLock(Mutex &mutex);
        ~ScopedLock();
    protected:
        Mutex &_mutex;
    private:
};

#endif /* !SCOPEDLOCK_HPP_ */
