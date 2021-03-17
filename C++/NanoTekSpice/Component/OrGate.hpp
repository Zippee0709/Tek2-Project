/*
** EPITECH PROJECT, 2020
** OrGate.hpp
** File description:
** OrGate
*/

#ifndef ORGATE_HPP
#define ORGATE_HPP
#include <iostream>
#include "Component.hpp"

namespace nts {
    class OrGate : public Component 
    {
        public:
            OrGate(std::string name);
            
            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;

            ~OrGate();
        private:
    };
}
#endif
