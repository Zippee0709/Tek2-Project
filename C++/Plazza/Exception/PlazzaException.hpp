/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** PlazzaException
*/

#ifndef PLAZZAEXCEPTION_HPP_
#define PLAZZAEXCEPTION_HPP_

#include <iostream>
#include <exception>

namespace PlazzaProject {
    class PlazzaException : public std::exception {
        public:
            PlazzaException(std::string const &message, std::string const &spot="Unknown");
            std::string const &getSpot() const;
            virtual const char* what() const throw();
            ~PlazzaException() throw() {};
        private:
            std::string _message;
            std::string _spot;
    };

    class MainParsingError : public PlazzaException {
        public:
            MainParsingError(std::string const &message, std::string const &spot="MainParsingError");        
    };

    class ReceptionError : public PlazzaException {
        public:
            ReceptionError(std::string const &message, std::string const &spot="ReceptionError");        
    };

    class PizzaTypeError : public ReceptionError {
        public:
            PizzaTypeError(std::string const &message, std::string const &spot="ReceptionError");        
    };

    class PizzaSizeError : public ReceptionError {
        public:
            PizzaSizeError(std::string const &message, std::string const &spot="ReceptionError");        
    };

    class PizzaNumberError : public ReceptionError {
        public:
            PizzaNumberError(std::string const &message, std::string const &spot="ReceptionError");        
    };


    class KitchenError : public PlazzaException {
        public:
            KitchenError(std::string const &message, std::string const &spot="KitchenError");        
    };
}

#endif /* !PLAZZAEXCEPTION_HPP_ */
