/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** SharedMemory
*/

#ifndef SHAREDMEMORY_HPP_
#define SHAREDMEMORY_HPP_

#include <iostream>
#include <sys/mman.h>
#include <string.h>
#include "PlazzaProject.hpp"

namespace PlazzaProject {
    class SharedMemory {
        public:
            SharedMemory();
            SharedMemory(void *shmap);
            void writeData(SharedMemoryData);
            void updateSharedMemory();
            void *getSharedMap() const { return _shmap;};
            SharedMemoryData getSharedMemoryData() const { return _shd; };
            ~SharedMemory();

        protected:
        private:
            void *_shmap;
            SharedMemoryData _shd;
    };
} // namespace

#endif /* !SHAREDMEMORY_HPP_ */
