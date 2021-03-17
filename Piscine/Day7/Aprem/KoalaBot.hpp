/*
** EPITECH PROJECT, 2020
** KoalaBot.hpp
** File description:
** KoalaBot.hpp
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string const &serial = "Bob-01");
        ~KoalaBot();
        void setParts(Arms const &parts);
        void setParts(Legs const &parts);
        void setParts(Head const &parts);
        void swapParts(Arms const &parts);
        void swapParts(Legs const &parts);
        void swapParts(Head const &parts);
        void informations() const;
        bool status() const;
    private:
        std::string _serial;
        Arms _arms;
        Legs _legs;
        Head _head;
};

#endif /* !KOALABOT_HPP_ */
