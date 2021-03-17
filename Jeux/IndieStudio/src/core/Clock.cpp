/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Clock
*/

#include "Clock.hpp"

namespace IndieStudio
{
    Clock::Clock()
    {
        _start = std::chrono::high_resolution_clock::now();
        _now = _start;
    }

    Clock::~Clock()
    {
    }

    std::chrono::high_resolution_clock::time_point Clock::getStart() const
    {
        return _start;
    }

    std::chrono::high_resolution_clock::time_point Clock::getNow() const
    {
        return _now;
    }

    float Clock::getDiff()
    {
        resetNow();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(_now - _start).count();

        return diff;
    }

    float Clock::getElapsedTimeInSecond()
    {
        resetNow();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(_now - _start).count();

        return diff / 1000.0;
    }

    float Clock::getElapsedTimeInMillisecond()
    {
        resetNow();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(_now - _start).count();

        return diff;
    }

    float Clock::getElapsedTimeInSecondWithStartPoint(std::chrono::high_resolution_clock::time_point timePoint)
    {
        resetNow();
        auto diff  = std::chrono::duration_cast<std::chrono::milliseconds>(_now - timePoint).count();

        return diff / 1000.0;
    }


    void Clock::resetNow()
    {
        _now = std::chrono::high_resolution_clock::now();
    }

    void Clock::restart()
    {
        _start = _now;
    }
}
