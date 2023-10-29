/*
** EPITECH PROJECT, 2022
** my_put_float
** File description:
** description
*/

#include "../../include/my.h"

void positiv(double f, int x)
{
    int i = 0;

    my_put_nbr(x);
    my_putchar('.');
    f = f - x;
    while (i < 5) {
        f = f * 10;
        x = (int) f;
        my_put_nbr(x);
        f = f - x;
        i++;
    }
    my_put_nbr(x);
}

void negativ(double f, int x)
{
    int i = 0;

    if (x == 0)
        my_putchar('-');
    my_put_nbr(x);
    f = f - x;
    f = f * -1;
    my_putchar('.');
    while (i < 5) {
        f = f * 10;
        x = (int) f;
        my_put_nbr(x);
        f = f - x;
        i++;
    }
    my_put_nbr(x);
}

double my_put_float(double f)
{
    int x = (int) f;
    int i = 0;

    if (f == x) {
        my_put_nbr(x);
        my_putchar('.');
        while (i < 6) {
            my_putchar('0');
            i++;
        }
    }
    if (f > 0)
        positiv(f, x);
    else if (f < 0)
        negativ(f, x);
}
