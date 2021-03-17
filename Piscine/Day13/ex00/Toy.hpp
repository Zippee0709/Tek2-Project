/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <iostream>
#include <fstream>
#include <string>

class Toy {
	public:
        enum ToyType {BASIC_TOY, ALIEN};
		Toy();
		Toy(Toy::ToyType type, std::string const &name, std::string const &file);
		~Toy();
        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        void setName(std::string const &name);
        bool setAscii(std::string const &file);
	protected:
	private:
        std::string _name;
        ToyType _type;
        std::string _picture;
};

#endif /* !TOY_HPP_ */
