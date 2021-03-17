/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Gate4030
*/

#ifndef GATE4030_HPP_
#define GATE4030_HPP_

#include "Component.hpp"

namespace nts {
    class Gate4030 : public nts::Component
    {
        public:
            Gate4030(std::string name);

            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;
            
            ~Gate4030();

        protected:
        private:
    };
}

#endif /* !GATE4030_HPP_ */

