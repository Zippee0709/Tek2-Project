/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "Component.hpp"

namespace nts {
    class True : public nts::Component{
        public:
            True(std::string name);
            nts::Tristate compute(std::size_t pin = 1);
            ~True();
        protected:
        private:
    };
}
#endif /* !TRUE_HPP_ */
