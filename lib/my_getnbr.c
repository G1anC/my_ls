/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** description
*/

#include "../include/my.h"

int	my_getnbr(char *string)
{
    int nbr = 0, j = 1, i = 0;

    for (; string[i] == '+' || string[i] == '-'; i++)
        j *= (string[i] == '-') ? -1 : 1;
    for (i; (string[i] >= '0' && string[i] <= '9') || string[i]; i++)
        nbr = (nbr * 10) + string[i] - '0';
    return nbr * j;
}
