/*
** EPITECH PROJECT, 2020
** Parts.hpp
** File description:
** Parts.hpp
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <string>
#include <iostream>
#include "Parts.hpp"

class Arms {
    public:
        Arms(std::string const &serial = "A-01", bool functionnal = true);
        ~Arms();
        bool isFunctionnal() const;
        std::string serial();
        void information() const;
    private:
        std::string _serial;
        bool _functionnal;
};

class Legs {
    public:
        Legs(std::string const &serial = "L-01", bool functionnal = true);
        ~Legs();
        bool isFunctionnal() const;
        std::string serial();
        void information() const;
    private:
        std::string _serial;
        bool _functionnal;
};

class Head {
    public:
        Head(std::string const &serial = "H-01", bool functionnal = true);
        ~Head();
        bool isFunctionnal() const;
        std::string serial();
        void information() const;
    private:
        std::string _serial;
        bool _functionnal;
};

#endif /* !PARTS_HPP_ */
