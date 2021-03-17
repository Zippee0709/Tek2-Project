/*
** EPITECH PROJECT, 2020
** Component.hpp
** File description:
** Component
*/

#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include <iostream>
#include "IComponent.hpp"
#include "../Parsing/Parsing.hpp"

namespace nts {
    Tristate operator|(const Tristate &state, const Tristate &state2);
    Tristate operator&(const Tristate &state, const Tristate &state2);
    Tristate operator!(const nts::Tristate &state);
    Tristate operatorXOR(const Tristate &state, const Tristate &state2);

    class Component : public nts::IComponent {
        public:
            Component(std::string name);
            
            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

            std::map<int, PinNamespace::Pin *> getPins() const;
            PinNamespace::Pin *getSinglePin(std::size_t pinId);
            void setPins(int, PinNamespace::Pin *);
            std::string getName() const;
            void reset();
            Parser::Type getType();
            // For debug ? To removed if not necessary
            void checkPinLink();
            
            ~Component() = default;
        protected:
            std::map<int, PinNamespace::Pin *> _Pins;
            std::string _name;
            Parser::Type _type;
    };
}
#endif
