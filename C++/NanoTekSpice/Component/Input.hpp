/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "Component.hpp"

namespace nts{
    class Input : public nts::Component {
        public:
            Input(std::string name);
            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;
            ~Input();
        protected:
        private:
    };
}
#endif /* !INPUT_HPP_ */
