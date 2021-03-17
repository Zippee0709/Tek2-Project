/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** InvalidArgv
*/

#ifndef INVALIDARGV_HPP_
#define INVALIDARGV_HPP_

#include <iostream>

namespace Exception {
    class InvalidArgv : std::exception
    {
        public:
            InvalidArgv(std::string const &message) throw();
            const char* what() const throw();
            ~InvalidArgv() throw();
        private:
            std::string _message;
    };
}
#endif /* !INVALIDARGV_HPP_ */

