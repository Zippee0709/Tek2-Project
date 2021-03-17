/*
** EPITECH PROJECT, 2020
** bootstrap_plaza
** File description:
** IMutex
*/

#ifndef IMUTEX_HPP_
#define IMUTEX_HPP_

class IMutex {
    public:
        virtual ~IMutex() = default;
        virtual void lock() = 0;
        virtual void unlock() = 0;
        virtual int trylock() = 0;
    protected:
    private:
};

#endif /* !IMUTEX_HPP_ */
