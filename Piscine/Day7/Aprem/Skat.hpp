/*
** EPITECH PROJECT, 2020
** Skap.hpp
** File description:
** Skat.hpp
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <string>
#include <iostream>

class Skat {
    public :
    Skat(const std::string &name = "bob", int stimPaks = 15);
    ~Skat();
    int& stimPaks();
    const std::string& name();
    void shareStimPaks(int number, int& stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();
    private:
    const std::string& _name;
    int _stimPaks;
};

#endif /* !SKAT_HPP_ */
