/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>

class Error : std::exception {
    public:
        Error(std::string const &message) throw();
        const char* what() const throw();

        ~Error();
    protected:
    private:
        std::string _message;
};

#endif /* !ERROR_HPP_ */
