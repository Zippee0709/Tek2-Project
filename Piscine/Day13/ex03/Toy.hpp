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
        enum ToyType {BASIC_TOY, ALIEN, BUZZ, WOODY};
		Toy();
		Toy(Toy::ToyType type, std::string const &name, std::string const &file);
        Toy(const Toy &toy);
        Toy operator=(const Toy &toy);
		~Toy();
        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        void setName(std::string const &name);
        bool setAscii(std::string const &file);
        virtual void speak(const std::string &statement) const;
	protected:
        std::string _name;
        ToyType _type;
        std::string _picture;
	private:
};

#endif /* !TOY_HPP_ */
