/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** main
*/

#include "Box.hpp"
#include "Teddy.hpp"
#include "PapaXmasElf.hpp"
#include "GiftPaper.hpp"

int		main(void)
{
    Object **obj = MyUnitTests();
    std::cout << obj[0][0].getTitle() << std::endl;
    std::cout << obj[0][1].getTitle() << std::endl;

    Object *Ted = new Teddy("Ted");
    Object *newBox = new Box;
    Object *newPaper = new GiftPaper;
    Object *tab[3];
    tab[0] = Ted;
    tab[1] = newBox;
    tab[2] = newPaper;
    Object *unit = MyUnitTests(tab);
    return 0;
}