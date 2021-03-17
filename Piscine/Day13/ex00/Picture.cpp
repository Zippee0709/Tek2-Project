/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture(const std::string &file)
{
    std::ifstream new_file;
    new_file.open(file);
    if (new_file.is_open() == true) {
        std::string line;
        while (getline(new_file, line)) {
            _data += line + "\n";
        }
    } else
        _data = "ERROR";
    new_file.close();
}

Picture::Picture()
{
    _data = "";
}

Picture::~Picture()
{
}

std::string Picture::getData()
{
    return (_data);
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream new_file;
    new_file.open(file);
    if (new_file.is_open() == true) {
        std::string line;
        while (getline(new_file, line))
            _data += line + "\n";
        new_file.close();
        return true;
    }
    _data = "ERROR";
    new_file.close();
    return false;
}
