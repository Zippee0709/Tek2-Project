/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include <iostream> 
#include "Component.hpp"

namespace nts {
    class Output : public Component{
        public:
            Output(std::string name);

            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;
            
            ~Output();

        protected:
        private:
    };
}

#endif /* !OUTPUT_HPP_ */
