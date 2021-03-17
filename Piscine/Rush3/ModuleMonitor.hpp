/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** ModuleMonitor
*/

#ifndef MODULEMONITOR_HPP_
#define MODULEMONITOR_HPP_

#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "KernelModule.hpp"
#include "OsModule.hpp"
#include "UsernameModule.hpp"
#include "CpuModule.hpp"
#include "RamModule.hpp"

class ModuleMonitor : public virtual DateTimeModule,
	public virtual HostnameModule, public virtual KernelModule,
	public virtual OsModule, public virtual UsernameModule, public CpuModule, public RamModule {
	public:

		ModuleMonitor();

		void update();
		std::string getHostname();
		std::string getUsername();
		std::string getOs();
		std::string getKernel();
		std::string getDateTime();
		int getCpuNbrProc(); // Nbr Proc currently available in the system
		int getConfNbrProc(); // Nbr Proc configured by the operating system
		std::map<std::string, std::string>getCPUinfo();
		std::map<std::string, long long>getRamInfo();

		~ModuleMonitor();
	
	protected:
		char _datetimeSTR[20];
	private:
};

#endif /* !MODULEMONITOR_HPP_ */
