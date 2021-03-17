/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** FourBitAdder
*/

#ifndef FOURBITADDER_HPP_
#define FOURBITADDER_HPP_

#include <iostream>
#include "Component.hpp"

namespace nts {
    class FourBitAdder : public Component
    {
        public:
            FourBitAdder(std::string name);

            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;

            ~FourBitAdder();
        private:
            nts::Tristate setCarryOut(const nts::Tristate &state, const nts::Tristate &state2,
                const nts::Tristate &CarryIn, nts::Tristate &CarryOut);
            nts::Tristate C2;
            nts::Tristate C3;
            nts::Tristate C4;
            nts::Tristate CO;
    };
}
#endif /* !FOURBITADDER_HPP_ */

