/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** KernelModule
*/

#ifndef KERNELMODULE_HPP_
#define KERNELMODULE_HPP_

#include "IModuleMonitor.hpp"

class KernelModule : public IModuleMonitor {
	public:
		KernelModule();

		void update();
		void readKernel();

		~KernelModule();

	protected:
        std::string _kernel;
	private:
};

#endif /* !KERNELMODULE_HPP_ */
