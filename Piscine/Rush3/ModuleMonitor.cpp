/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** ModuleMonitor
*/

#include <sstream>
#include "ModuleMonitor.hpp"
#include "time.h"

ModuleMonitor::ModuleMonitor() : DateTimeModule(), HostnameModule(),
								 KernelModule(), UsernameModule(), OsModule()
{
}

ModuleMonitor::~ModuleMonitor()
{
}

void ModuleMonitor::update()
{
	DateTimeModule::update();
	KernelModule::update();
	UsernameModule::update();
	OsModule::update();
	HostnameModule::update();
	CpuModule::update();
}

std::string ModuleMonitor::getHostname()
{
	readHostname();
	return _hostname;
}

std::string ModuleMonitor::getUsername()
{
	readUsername();
	return _username;
}

std::string ModuleMonitor::getOs()
{
	readOsName();
	return _osname;
}

std::string ModuleMonitor::getKernel()
{
	readKernel();
	return _kernel;
}

std::string ModuleMonitor::getDateTime()
{
	readDateTime();

	strftime(_datetimeSTR, 20, "%Y-%m-%d %H:%M:%S", localtime(&_datetime));

	return _datetimeSTR;
}

int ModuleMonitor::getConfNbrProc()
{
	readNbrCpu();

	return _conf_nbr_proc;
}

int ModuleMonitor::getCpuNbrProc()
{
	readNbrCpu();

	return _nbr_proc;
}

std::map<std::string, std::string> ModuleMonitor::getCPUinfo()
{
	if (read_cpu_file() == false) {
		std::cout << "Failed read CPU file" << std::endl;
		_all_cpu_info["processor 0"] = nullptr;
	}
	return (_all_cpu_info);
}

std::map<std::string, long long> ModuleMonitor::getRamInfo()
{
	ReadRam();

	return _ram_info;
}