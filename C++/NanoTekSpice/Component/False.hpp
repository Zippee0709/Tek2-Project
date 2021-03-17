/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "Component.hpp"

namespace nts {
    class False : public nts::Component{
        public:
            False(std::string name);
            nts::Tristate compute(std::size_t pin = 1);
            ~False();
        protected:
        private:
    };
}
#endif /* !FALSE_HPP_ */
