/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "Component.hpp"

namespace nts{
    class Clock : public nts::Component{
        public:
            Clock(std::string name);
            nts::Tristate compute(std::size_t pin = 1);
            ~Clock();
        protected:
        private:
    };
}

#endif /* !CLOCK_HPP_ */
