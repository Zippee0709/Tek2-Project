/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NandGate
*/

#ifndef NANDGATE_HPP_
#define NANDGATE_HPP_

#include <iostream>
#include "Component.hpp"

namespace nts {
    class NandGate : public Component
    {
        public:
            NandGate(std::string name);

            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;

            ~NandGate();
        private:
    };
}
#endif /* !NandGate_HPP_ */

