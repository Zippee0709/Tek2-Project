/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AndGate
*/

#ifndef ANDGATE_HPP_
#define ANDGATE_HPP_

#include <iostream>
#include "Component.hpp"

namespace nts {
    class AndGate : public Component
    {
        public:
            AndGate(std::string name);

            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;

            ~AndGate();
        private:
    };
}
#endif /* !ANDGATE_HPP_ */

