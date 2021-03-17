/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Argv
*/

#include "Argv.hpp"
#include "Exception/InvalidArgv.hpp"

Parser::Argv::Argv(int ac, char **av)
{
    if (ac < 2)
        throw Exception::InvalidArgv("Error: Pleaser specified .nts file");
    std::string filename(av[1]);
    if (filename.find(".nts") == -1)
        throw Exception::InvalidArgv("Error: File must be in .nts format");
    _fileName = filename;
    for (std::size_t i = 2; i < ac; i++) {
        std::string input(av[i]);
        int pos = input.find_first_of('=');
        if (av[i][pos] != '=' || pos + 1 == std::string::npos)
            throw Exception::InvalidArgv("Error: Input must have '=' sign and assignation");
        std::string inputName(input.substr(0, pos));
        std::string inputValue(input.substr(pos + 1));
        if(inputName.size() == 0)
            throw Exception::InvalidArgv("Error: Input must have a name");
        if(inputValue != "0" && inputValue != "1")
            throw Exception::InvalidArgv("Error: Input value must be 0 or 1");
        std::pair<std::string, std::string> inputPair(inputName, inputValue);
        _input[inputName] = inputValue;
    }
}

Parser::Argv::~Argv()
{
}

std::string Parser::Argv::getFileName() const
{
    return _fileName;
}
std::map<std::string, std::string>Parser::Argv::getAllInput() const
{
    return _input;
}
