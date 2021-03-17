/*
** EPITECH PROJECT, 2020
** NorGate.hpp
** File description:
** NorGate
*/

#ifndef NORGATE_HPP
#define NORGATE_HPP
#include <iostream>
#include "Component.hpp"
namespace nts {
    class NorGate : public nts::Component 
    {
        public:
            NorGate(std::string name);
            
            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;

            ~NorGate();
        private:
    };
}

#endif
