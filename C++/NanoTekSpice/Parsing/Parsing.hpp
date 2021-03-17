/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
#define PARSING_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include "Argv.hpp"
#include "../Exception/InvalidArgv.hpp"

namespace Parser {
    enum Type {
        INPUT,
        OUTPUT,
        TRUE,
        FALSE,
        CLOCK,
        GATE2716,
        GATE4001,
        GATE4008,
        GATE4011,
        GATE4013,
        GATE4017,
        GATE4030,
        GATE4040,
        GATE4069,
        GATE4071,
        GATE4081,
        GATE4094,
        GATE4503,
        GATE4512,
        GATE4514,
        GATEI4004,
        GATEMK4801,
        UNDEFINE
    };
    class Parsing {
        public:
            Parsing(int ac, char **av);
            ~Parsing();
            std::string getData() const;
            std::map<std::string, Parser::Type> getChipsetsVector() const;
            std::map<std::string, std::string> getLinksVector() const;
        private:
            void read_file();
            void check_line(std::ifstream &file, std::string const &line);
            void parse_information(std::ifstream &file);
            int get_nb_of_words(std::string const &string) const;
            void save_information_in_chipsets(std::string &line);
            void save_information_in_links(std::string &line);
            bool check_same_name(std::string const &name) const;
            std::string clean_str(std::string &str);

            std::string _data;
            Parser::Argv _argv;
            std::map<std::string, Parser::Type> _chipsets;
            std::map<std::string, std::string> _links;
    };
}

#endif /* !PARSING_HPP_ */