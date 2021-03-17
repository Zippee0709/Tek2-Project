/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** main.cpp
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

float my_convert_celsius_to_fahrenheit(std :: string input)
{
    std :: istringstream iss(input);
    std :: string type;
    float res = 0;

    iss >> res >> type;
    res = (9.0 / 5.0 * res) + 32.0;
    std :: cout.precision(3);
    std :: cout << std :: setw(16) << std :: fixed << res << std :: setw(16) << "Fahrenheit" << std::endl;
    return (res);
}

float my_convert_fahrenhein_to_celsius(std :: string input)
{
    std :: istringstream iss(input);
    std :: string type;
    float res = 0;

    iss >> res >> type;
    res = 5.0 / 9.0 * (res - 32.0);
    std :: cout.precision(3);
    std :: cout << std :: setw(16) << std :: fixed << res << std :: setw(16) << "Celsius" << std::endl;
    return (res);
}

int main(void)
{
    std :: string input;
    getline(std :: cin, input);
    if (input.find("Celsius") != std :: string :: npos)
        my_convert_celsius_to_fahrenheit(input);
    else if (input.find("Fahrenheit") != std :: string :: npos)
        my_convert_fahrenhein_to_celsius(input);
    else
        std :: cerr << "Error: Invalid type\n" << std :: endl;
    return (0);
}
