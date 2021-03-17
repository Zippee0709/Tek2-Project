/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Error
*/

#pragma once
#include <iostream>

class Error : public std::exception
{
    public:
        Error(std::string const &message="",
                std::string const &functionPart = "Unknown") noexcept : _message(message), _functionPart(functionPart) {};
        ~Error() = default;

        std::string const &getFunctionPart() const noexcept { return _functionPart; };
        virtual const char *what() const noexcept override { return _message.c_str(); };

        template <typename T>
        void error(const T &aLog, const std::string &message = "") const noexcept
        {
            std::cerr << message << aLog << std::endl;
        }

    private:
        std::string _message;
        std::string _functionPart;
};