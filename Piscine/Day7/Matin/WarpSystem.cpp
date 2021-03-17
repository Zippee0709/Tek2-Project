/*
** EPITECH PROJECT, 2020
** WarpSystem
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
    _stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
    
}

bool WarpSystem::QuantumReactor :: isStable(void)
{
    if(_stability == true)
        return (true);
    return(false);
}

void WarpSystem::QuantumReactor :: setStability(bool stability)
{
    if (stability == true)
        _stability = true;
    else if (stability == false)
        _stability = false;
}

WarpSystem::Core :: Core(WarpSystem::QuantumReactor *Reactor)
{
    _coreReactor = Reactor;
}

WarpSystem::Core :: ~Core(void)
{

}

WarpSystem::QuantumReactor * WarpSystem::Core :: checkReactor(void)
{
    return (_coreReactor);
}
