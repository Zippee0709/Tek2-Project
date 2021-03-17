/*
** EPITECH PROJECT, 2020
** bootstrap_plaza
** File description:
** MutexException
*/

#ifndef MUTEXEXCEPTION_HPP_
#define MUTEXEXCEPTION_HPP_

#include <exception>
#include <iostream>

class MutexException : std::exception {
    public:
        MutexException(std::string const &message) throw();
        const char* what() const throw();
        ~MutexException();
    protected:
        std::string _message;
    private:
};

#endif /* !MUTEXEXCEPTION_HPP_ */
