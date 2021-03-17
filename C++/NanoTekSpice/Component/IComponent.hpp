/*
** EPITECH PROJECT, 2020
** bootstrap_nanotekspice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_
#include <cstddef>
#include <map>

namespace PinNamespace { class Pin; }

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    
    class IComponent {
        public:
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual PinNamespace::Pin *getSinglePin(std::size_t pinId) = 0;
            virtual ~IComponent() = default;
    };
}

#endif /* !ICOMPONENT_HPP_ */
