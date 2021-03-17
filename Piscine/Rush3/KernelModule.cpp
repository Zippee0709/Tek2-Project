/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** KernelModule
*/

#include <iostream>
#include <fstream>
#include "KernelModule.hpp"

KernelModule::KernelModule()
{
}

KernelModule::~KernelModule()
{
}

void KernelModule::readKernel()
{
    std::ifstream kernelFile("/proc/version");

    if (kernelFile.is_open()) 
    {   
        std::getline(kernelFile, _kernel, ' ');
        std::getline(kernelFile, _kernel, '(');
        kernelFile.close();
    } else {
        std::cerr << "Can't open File" << std::endl;
    }
}

void KernelModule::update()
{
    readKernel();
}