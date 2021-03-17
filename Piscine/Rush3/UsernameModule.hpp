/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UsernameModule
*/

#ifndef USERNAMEMODULE_HPP_
#define USERNAMEMODULE_HPP_

#include "IModuleMonitor.hpp"
#include <iostream>

class UsernameModule : public IModuleMonitor {
	public:
		UsernameModule() = default;

		void update();
		void readUsername();

		~UsernameModule() = default;

	protected:
		std::string _username;
	private:
};

#endif /* !USERNAMEMODULE_HPP_ */
