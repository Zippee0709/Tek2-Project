/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parsing
*/

#include "Parsing.hpp"

Parser::Parsing::Parsing(int ac, char **av) : _argv(ac, av)
{
    read_file();
}

Parser::Parsing::~Parsing()
{
}

std::string Parser::Parsing::getData() const
{
    return _data;
}

std::map<std::string, Parser::Type> Parser::Parsing::getChipsetsVector() const
{
    return _chipsets;
}

std::map<std::string, std::string> Parser::Parsing::getLinksVector() const
{
    return _links;
}

void Parser::Parsing::read_file()
{
    std::ifstream file(_argv.getFileName());
    if (file) {
        std::string line;
        while (getline(file, line))
            check_line(file, line);
        file.close();
    } else
        throw Exception::InvalidArgv("Error: File.nts not found");
}

void Parser::Parsing::check_line(std::ifstream &file, std::string const &line)
{
    if (line.find("#") == std::string::npos)  {
        if (line.find(".chipsets:") != std::string::npos)
            parse_information(file);
    }
}

void Parser::Parsing::parse_information(std::ifstream &file)
{
    std::string line = "";
    int nb_of_words = 0;

    while (getline(file, line) && line != ".links:") {
        nb_of_words = get_nb_of_words(line);
        if (nb_of_words == 2) {
            save_information_in_chipsets(line);
        }
        else if (nb_of_words > 2 || nb_of_words == 1)
            throw Exception::InvalidArgv("Error: .chipsets: information must be stringA and stringB only");
    }
    while (getline(file, line)) {
        nb_of_words = get_nb_of_words(line);
        if (nb_of_words == 2)
            save_information_in_links(line);
        else if (nb_of_words > 2 || nb_of_words == 1)
            throw Exception::InvalidArgv("Error: .links: information must be stringA and stringB only");
    }
}

std::string Parser::Parsing::clean_str(std::string &str)
{
    std::string new_string = "";
    int i = 0;
    int j = 0;
    const char *ptr = str.c_str();

    for (; ptr[i] != '\0'; i++) {
        if ((ptr[i] != ' ' && ptr[i] != '\t')) {
            j = 0;
            new_string += str[i];
        }
        else if (j == 0) {
            new_string += ' ';
            j = 1;
        }
    }
    return new_string;
}

void Parser::Parsing::save_information_in_chipsets(std::string &line)
{
    if (line[0] == '#')
        return;
    line = clean_str(line);
    std::string first_word = line.substr(0, line.find(" "));
    std::string second_word = line.substr(line.find(" ") + 1);
    Parser::Type first_type = Parser::Type::UNDEFINE;

    if (first_word == "input")
        first_type = Parser::Type::INPUT;
    else if (first_word == "output")
        first_type = Parser::Type::OUTPUT;
    else if (first_word == "true")
        first_type = Parser::Type::TRUE;
    else if (first_word == "false")
        first_type = Parser::Type::FALSE;
    else if (first_word == "clock")
        first_type = Parser::Type::CLOCK;
    else if (first_word == "2716")
        first_type = Parser::Type::GATE2716;
    else if (first_word == "4001")
        first_type = Parser::Type::GATE4001;
    else if (first_word == "4008")
        first_type = Parser::Type::GATE4008;
    else if (first_word == "4011")
        first_type = Parser::Type::GATE4011;
    else if (first_word == "4013")
        first_type = Parser::Type::GATE4013;
    else if (first_word == "4017")
        first_type = Parser::Type::GATE4017;
    else if (first_word == "4030")
        first_type = Parser::Type::GATE4030;
    else if (first_word == "4040")
        first_type = Parser::Type::GATE4040;
    else if (first_word == "4069")
        first_type = Parser::Type::GATE4069;
    else if (first_word == "4071")
        first_type = Parser::Type::GATE4071;
    else if (first_word == "4081")
        first_type = Parser::Type::GATE4081;
    else if (first_word == "4094")
        first_type = Parser::Type::GATE4094;
    else if (first_word == "4503")
        first_type = Parser::Type::GATE4503;
    else if (first_word == "4512")
        first_type = Parser::Type::GATE4512;
    else if (first_word == "4514")
        first_type = Parser::Type::GATE4514;
    else if (first_word == "i4004")
        first_type = Parser::Type::GATEI4004;
    else if (first_word == "mk4801")
        first_type = Parser::Type::GATEMK4801;
    else
        first_type = Parser::Type::UNDEFINE;

    if (check_same_name(second_word) == true)
        throw Exception::InvalidArgv("The name :" + second_word + "is already taken");
    _chipsets.insert(std::make_pair(second_word, first_type));
}

void Parser::Parsing::save_information_in_links(std::string &line)
{
    if (line[0] == '#')
        return;
    line = clean_str(line);
    std::string first_word = line.substr(0, line.find(" "));
    std::string second_word = line.substr(line.find(" ") + 1);

    _links.insert(std::make_pair(first_word, second_word));
}

bool Parser::Parsing::check_same_name(std::string const &name) const
{
    for (auto const &component : _chipsets) {
        if (component.first == name)
            return true;
    }
    return false;
}

int Parser::Parsing::get_nb_of_words(std::string const &string) const
{
    char const *str = string.c_str();
    int i = 0;
    int nb_words = 0;
    bool state = false;

    if (str[i] == '\0' || str[i] == '\n')
        return nb_words;
    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            state = false;
        else if (state == false) {
            state = true;
            nb_words += 1;
        }
    }
    return nb_words;
}
