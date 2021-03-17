/*
** EPITECH PROJECT, 2020
** cpp_d16_2019
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser()
{
    _result = 0;
    _str = "";
}

Parser::~Parser()
{

}

int my_check_operand(char c)
{
    if (c == '*' || c == '/' || c == '%')
        return 1;
    else if (c == '+' || c == '-')
        return 2;
    return 0;
}

bool my_check_nb(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

int my_getnbr(const std::string &str, size_t *i)
{
    int value = 0;

    while (*i < str.length() && my_check_nb(str[*i]) == true) {
        value = (value * 10) + str[*i] - '0';
        *i = *i + 1;
    }
    return value;
}

int my_calc(int nb1, int nb2, char operand)
{
    if (operand == '*')
        return nb1 * nb2;
    else if (operand == '/')
        return nb1 / nb2;
    else if (operand == '%')
        return nb1 % nb2;
    else if (operand == '+')
        return nb1 + nb2;
    else if (operand == '-')
        return nb1 - nb2;
    return 0;
}

void my_calc_expr(std::stack<int> &value, std::stack<char> &operand)
{
    int nb1 = 0;
    int nb2 = 0;
    char charac = 0;
    int resultat = 0;

    for (; operand.top() != '('; operand.pop()) {
        nb2 = value.top();
        value.pop();
        nb1 = value.top();
        value.pop();
        charac = operand.top();
        resultat = my_calc(nb1, nb2, charac);
        value.push(resultat);
    }
    operand.pop();
}

void Parser::feed(const std::string &data)
{
    _str = data;
    size_t i;
    int nbr = 0;
    std::stack<int> value;
    std::stack<char> operand;

    for (i = 0; i < data.length(); i++) {
        if (data[i] == '(')
            operand.push(data[i]);
        if (my_check_nb(data[i]) == true) {
            nbr = my_getnbr(data, &i);
            value.push(nbr);
        }
        if (my_check_operand(data[i]) != 0)
            operand.push(data[i]);
        if (data[i] == ')')
            my_calc_expr(value, operand);
    }
    _result = _result + value.top();
}

int Parser::result()
{
    return _result;
}

void Parser::reset()
{
    _result = 0;
    _str = "";
}
