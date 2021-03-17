/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Argv
*/

#ifndef ARGV_HPP_
#define ARGV_HPP_
#include <iostream>
#include <map>
#include <string>
#include <fstream>

namespace Parser {
    class Argv {
        public:
            Argv(int ac, char **av);
            ~Argv();
            std::string getFileName() const;
            std::map<std::string, std::string> getAllInput() const;
        protected:
        private:
            std::string _fileName;
            std::map<std::string, std::string> _input;
    };
}
#endif /* !ARGV_HPP_ */