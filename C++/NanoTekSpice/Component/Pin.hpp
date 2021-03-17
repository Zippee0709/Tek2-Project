/*
** EPITECH PROJECT, 2020
** Pin.hpp
** File description:
** Pin
*/

#ifndef PIN_HPP
#define PIN_HPP
#include <iostream>
#include "Component.hpp"

namespace PinNamespace {
    enum pinType {
        Input,
        Output
    };

    class Pin {
        public:
            Pin(std::size_t id, nts::Component *actual, const pinType type)
            : _id(id), _actual(actual), _type(type), _state(nts::Tristate::UNDEFINED), _otherPin(nullptr) { };

            pinType getType() const;
            nts::Tristate getState();
            nts::Component *getActualComponent() const;
            Pin *getOtherPin();
            std::size_t getId();
            void setOtherPin(Pin *);
            void setState(nts::Tristate value);
            ~Pin() = default;
        private:
            nts::Component *_actual;
            pinType _type;
            nts::Tristate _state;
            Pin *_otherPin;
            std::size_t _id;
    };
}

#endif
