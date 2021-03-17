/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** ThreadException
*/

#ifndef THREADEXCEPTION_HPP_
#define THREADEXCEPTION_HPP_

#include <exception>
#include <iostream>

class ThreadException {
    public:
        ThreadException(std::string const &message) throw();
        const char* what() const throw();
        ~ThreadException();
    protected:
        std::string _message;
    private:};

#endif /* !THREADEXCEPTION_HPP_ */
