/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** RamModule
*/

#include <syscall.h>
#include "ModuleMonitor.hpp"
#include "RamModule.hpp"

RamModule::RamModule()
{
}

RamModule::~RamModule()
{
}

void RamModule::ReadRam()
{
    if (sysinfo(&sysInfo) == -1)
        return;
/*     double totalRam = ((sysInfo.totalram * sysInfo.mem_unit) / 1024 / 1024);
    totalRam /= 1024;
    double freeRam = ((sysInfo.freeram * sysInfo.mem_unit) / 1024 / 1024);
    freeRam /= 1024;
    double ramUsed = ((sysInfo.totalram * sysInfo.mem_unit) - (sysInfo.freeram * sysInfo.mem_unit)) / 1024 / 1024;
    ramUsed /= 1024;
 */    
    std::map<std::string, long long> ram_info;
    long long totalRam = sysInfo.totalram;
    totalRam = totalRam / 1024  ;
    std::cout << "Total : " << totalRam << std::endl;
    long long ramUsed = sysInfo.totalram - sysInfo.freeram - sysInfo.bufferram; // NEED : -cache
    ramUsed = ramUsed / 1024 ;
    std::cout << "Used : " << ramUsed << std::endl;

    long long freeRam = sysInfo.freeram;
    freeRam = freeRam / 1024 ;
    std::cout << "Free : " << freeRam << std::endl;

    long long sharedRam = sysInfo.sharedram;
    sharedRam = sharedRam / 1024 ;
    std::cout << "Share : " << sharedRam << std::endl;

    long long buff = sysInfo.bufferram;// NEED: + cache
    buff = buff / 1024 ;
    std::cout << "Buffer : " << buff << std::endl;

    std::cout << "Test : " << (sysInfo.loads[0] * sysInfo.mem_unit) / 1024 << std::endl;
    std::cout << sysInfo.procs << std::endl;
    ram_info["Total"] = totalRam;
    ram_info["Used"] = ramUsed;
    ram_info["Free"] = freeRam;
    ram_info["Share"] = sharedRam;
    ram_info["Buffer"] = buff;
    this->_ram_info = ram_info;
}


void RamModule::update()
{
    ReadRam();
}