/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** PinException
*/

#ifndef PINEXCEPTION_HPP_
#define PINEXCEPTION_HPP_

#include <iostream>

namespace Exception {
    class PinException : public std::exception {
        public:
            PinException(const std::string &message) throw();
            const char* what () const throw ();
            ~PinException() throw();
        private:
            std::string _message;
    };
}
#endif /* !PINEXCEPTION_HPP_ */
