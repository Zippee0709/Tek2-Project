/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <fstream>
#include <string>

class Picture {
    public:
        Picture();
        Picture(const Picture &picture);
        Picture operator=(const Picture &picture);
        Picture(const std::string &file);
        ~Picture();
        bool getPictureFromFile(const std::string &file);
        std::string getData() const;
    protected:
	private:
        std::string _data;
};

#endif /* !PICTURE_HPP_ */
