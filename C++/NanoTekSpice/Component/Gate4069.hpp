/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** InvertedCircuit
*/

#ifndef GATE4069_HPP_
#define GATE4069_HPP_

#include "Component.hpp"

namespace nts {
    class Gate4069 : public nts::Component
    {
        public:
            Gate4069(std::string name);

            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;

            ~Gate4069();
        protected:
        private:
    };
}
#endif /* !INVERTEDCIRCUIT_HPP_ */
