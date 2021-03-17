/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <string>
#include <stack>

class Parser {
	public:
		Parser();
		~Parser();
        void feed(const std::string &);
        int result();
        void reset();
        // int my_getnbr(const std::string &str, size_t *i);
	protected:
	private:
        int _result;
        std::string _str;
};

#endif /* !PARSER_HPP_ */