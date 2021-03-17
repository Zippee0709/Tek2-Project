/*
** EPITECH PROJECT, 2020
** rush1
** File description:
** ex04
*/


#include <stdio.h>
#include "new.h"
#include "char.h"

void compareAndDivide ( Object *a , Object * b )
{
    printf("opop\n");
    if ( gt (a , b ) )
        printf ("a est plus grand a > b \n");
    if (lt (a , b ))
        printf ("a est plus petit a < b \n");
    if (eq(a, b))
        printf ("a est eq a == b\n");
}

void main (void) 
{
    Object *pb = new(Char, '9');
    Object *pa = new(Char, '3');
    compareAndDivide(pa, pb);
    printf ("b + a = %s et le vrai = %c\n" , str(addition (pb , pa)), '9' + '3');

    pb = new(Char, 'z');
    pa = new(Char, '0');
    printf ("b - a = %s et le vrai = %c\n" , str(subtraction (pb , pa)), 'z' - '0');
    
    pb = new(Char, '\b');
    pa = new(Char, '\t');
    printf ("b * a = %s et le vrai = %c\n" , str(multiplication (pb , pa)), '\b' * '\t');
    
    pb = new(Char, '~');
    pa = new(Char, '2');
    printf ("b  a = %s et le vrai = %c\n" , str(division (pb , pa)), '~' / '2');
}