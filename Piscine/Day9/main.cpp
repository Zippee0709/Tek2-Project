/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "Character.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Priest.hpp"
#include "Paladin.hpp"

int main()
{
    Character kreog("Kreog", 21);

    std::cout << "[" + kreog.getName() + "] lvl " << kreog.getLvl() << " enter in tek donjon" << std::endl << "------------Fight---------------" << std::endl;
    kreog.RangeAttack();
    kreog.CloseAttack();
    kreog.TakeDamage(84);
    std::cout << kreog.getName() + " checks his life level => " << kreog.getPv() << std::endl;
    kreog.Heal();
    std::cout << "life restored => " << kreog.getPv() << std::endl;
    kreog.Heal();
    std::cout << "life restored => " << kreog.getPv() << std::endl;
    std::cout << kreog.getName() + " checks his power level => " << kreog.getPower() << std::endl;
    kreog.RestorePower();
    std::cout << "Power restored => " << kreog.getPower() << std::endl << "------------New Player---------------" << std::endl;

    Warrior thor("Thor", 42);
    std::cout << thor.getName() + " lvl " << thor.getLvl() << " joins the team" << std::endl;
    thor.RangeAttack();
    thor.TakeDamage(60);
    thor.CloseAttack();
    std::cout << "------------End Fight---------------" << std::endl;
    thor.Heal();
    std::cout << thor.getName() + " pv : " << thor.getPv() << std::endl;
    std::cout << thor.getName() + " power : " << thor.getPower() << std::endl;
    kreog.RestorePower();
    thor.RestorePower();
    std::cout << "------------New Player---------------" << std::endl;
    Mage fluffy("Fluffy", 40);
    fluffy.CloseAttack();
    fluffy.TakeDamage(91);
    fluffy.RangeAttack();
    std::cout << fluffy.getName() + " pv : " << fluffy.getPv() << std::endl;
    fluffy.Heal();
    fluffy.TakeDamage(84);
    fluffy.RangeAttack();
    std::cout << fluffy.getName() + " pv : " << fluffy.getPv() << std::endl;
    fluffy.Heal();
    fluffy.Heal();
    std::cout << fluffy.getName() + " pv : " << fluffy.getPv() << std::endl;
    fluffy.RestorePower();
    std::cout << "------------New Player---------------" << std::endl;
    Priest iopi("Iopi", 84);
    iopi.CloseAttack();
    iopi.RangeAttack();
    iopi.TakeDamage(75);
    std::cout << iopi.getName() + " pv : " << iopi.getPv() << std::endl;
    iopi.Heal();
    std::cout << iopi.getName() + " pv : " << iopi.getPv() << std::endl;
    iopi.RangeAttack();
    iopi.Heal();
    iopi.RestorePower();
    std::cout << "------------New Player---------------" << std::endl;
    Paladin pala("Paladin", 50);
}