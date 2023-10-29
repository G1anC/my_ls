/*
** EPITECH PROJECT, 2022
** flag_1
** File description:
** page 1 des fonctions des différents flags
*/

#include <stdio.h>
#include "../../include/my.h"

void flag_d(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

void flag_i(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

int my_put_nbr_unsigned(unsigned int nb)
{
    unsigned int compt = 0;
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        compt++;
    }
    if (nb >= 10) {
        my_put_nbr_unsigned(nb / 10);
        my_put_nbr_unsigned(nb % 10);
        compt++;
    } else {
        my_putchar(nb + '0');
        compt++;
    }
    return compt;
}

void flag_u(va_list list)
{
    my_put_nbr_unsigned(va_arg(list, unsigned int));
}

void flag_f(va_list list)
{
    my_put_float(va_arg(list, double));
}
