/*
** EPITECH PROJECT, 2020
** Droid.hpp
** File description:
** Droid.hpp
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>
#include <string>

class Droid {
	public:
		Droid(std::string Id = "");
        Droid(Droid const &droid);
		~Droid();
        //getter
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;
        //setter
        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        //operator
        void operator=(const Droid &droid);
        bool operator==(const Droid &droid);
        bool operator!=(const Droid &droid);
        void operator<<(size_t &energy);
	private:
        std::string Id;
        size_t Energy;
        const size_t Attack;
        const size_t Toughness;
        std::string *Status;
};

std::ostream& operator<<(std::ostream &flux, Droid const &droid);
#endif /* !DROID_HPP_ */
