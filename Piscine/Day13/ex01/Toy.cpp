/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy() : _name("toy"), _type(BASIC_TOY), _picture("")
{
}

Toy::Toy(ToyType type, std::string const &name, std::string const &file)
{
    _type = type;
    _name = name;
    setAscii(file);
}

Toy::~Toy()
{
}

Toy::Toy(const Toy &toy)
{
    _type = toy.getType();
    _name = toy.getName();
    _picture = toy.getAscii();
}

Toy Toy::operator=(const Toy &toy)
{
    _type = toy.getType();
    _name = toy.getName();
    _picture = toy.getAscii();
    return (*this);
}


Toy::ToyType Toy::getType() const
{
    return _type;
}
std::string Toy::getName() const
{
    return _name;
}
std::string Toy::getAscii() const
{
    return _picture;
}

void Toy::setName(std::string const &name)
{
    _name = name;
}

bool Toy::setAscii(std::string const &file)
{
    std::ifstream new_file;
    new_file.open(file);
    if (new_file.is_open() == true) {
        std::string line;
        while (getline(new_file, line))
            _picture += line + "\n";
        new_file.close();
        return true;
    }
    _picture = "ERROR";
    return false;
}
