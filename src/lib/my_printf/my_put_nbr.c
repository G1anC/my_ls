/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** description
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int compt = 0;
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        compt++;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
        compt++;
    } else {
        my_putchar(nb + '0');
        compt++;
    }
    return compt;
}
