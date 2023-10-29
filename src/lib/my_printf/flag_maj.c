/*
** EPITECH PROJECT, 2022
** flag_maj.c
** File description:
** sus
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../../include/my.h"


void argx_maj(int arg)
{
    if (arg >= 16)
        argx(arg / 16);
    my_putchar("0123456789ABCDEF"[arg % 16]);
}

void flag_x_maj(va_list list)
{
    int arg = va_arg(list, int);
    argx_maj(arg);
}

void flag_e_max(va_list list)
{
    return;
}
