/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** my_printf en meilleur
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
}
