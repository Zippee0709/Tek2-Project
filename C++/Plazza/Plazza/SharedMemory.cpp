/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** SharedMemory
*/

#include "SharedMemory.hpp"

namespace PlazzaProject {

SharedMemory::SharedMemory()
{
    _shmap = mmap(NULL, sizeof(SharedMemoryData), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
}

SharedMemory::SharedMemory(void *shmap)
{
    _shmap = shmap;
}

SharedMemory::~SharedMemory()
{
}

void SharedMemory::updateSharedMemory()
{
    _shd = *(SharedMemoryData *)_shmap;
}

void SharedMemory::writeData(SharedMemoryData shd)
{
    _shd = shd;
    memcpy(_shmap, &shd, sizeof(shd));
}

} // namespace


