/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <chrono>
#include <ctime>
#include <iostream>

namespace IndieStudio {
    class Clock {
        public:
            Clock();
            ~Clock();
            std::chrono::high_resolution_clock::time_point getStart() const;
            std::chrono::high_resolution_clock::time_point getNow() const;
            void restart();
            float getDiff();
            float getElapsedTimeInSecond();
            float getElapsedTimeInMillisecond();
            float getElapsedTimeInSecondWithStartPoint(std::chrono::high_resolution_clock::time_point timePoint);
        protected:
        private:
            void resetNow();
            std::chrono::high_resolution_clock::time_point _start;
            std::chrono::high_resolution_clock::time_point _now;
    };
}

#endif /* !CLOCK_HPP_ */