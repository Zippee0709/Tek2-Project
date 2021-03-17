/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** CpuModule
*/

#include "CpuModule.hpp"

CpuModule::CpuModule()
{
}

CpuModule::~CpuModule()
{
}

void CpuModule::update()
{
    readNbrCpu();
    read_cpu_file();
}

void CpuModule::fill_cpu_info(std::string name, std::string value)
{
    this->_all_cpu_info[name] = value;
}

std::string concatNameMapCpu(std::string first, std::string second)
{
    std::string str_tmp = first;
    first.append(second);
    return first;
}

bool CpuModule::read_cpu_file()
{
    std::ifstream file;
    std::string num_cpu;
    file.open("/proc/cpuinfo");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line, ':')) {
            std::remove_if(line.begin(), line.end(), isspace);
            if (line.find("processor") != std::string::npos) {
                getline(file, line);
                std::string str_tmp = concatNameMapCpu("processor", line);
                num_cpu = line;
                fill_cpu_info(str_tmp, line);
            }
            if (line.find("modelname") != std::string::npos) {
                getline(file, line);
                std::string str_tmp = concatNameMapCpu("model name", num_cpu);
                fill_cpu_info(str_tmp, line);
            }
            if (line.find("cpuMHz") != std::string::npos) {
                getline(file, line);
                std::string str_tmp = concatNameMapCpu("CPU Mhz", num_cpu);
                fill_cpu_info(str_tmp, line);
            }
        }
        file.close();
    }
    else
        return false;
    return true;
}

void CpuModule::readNbrCpu()
{
    this->_nbr_proc = get_nprocs();
    this->_conf_nbr_proc = get_nprocs_conf();
    if (read_cpu_file() == false)
        std::cerr << "Failed open CPUinfo" << std::endl;
}