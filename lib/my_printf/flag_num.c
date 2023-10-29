/*
** EPITECH PROJECT, 2022
** flag_num.c
** File description:
** sus
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../../include/my.h"

void flag_o(va_list list)
{
    int arg = va_arg(list, int);
    int result = 0;
    int i = 1;
    while (arg != 0) {
        result += (arg % 8) * i;
        arg = arg / 8;
        i = i * 10;
    }
    my_put_nbr(result);
}

void flag_b(va_list list)
{
    int arg = va_arg(list, int);
    int result = 0;
    int i = 1;
    while (arg != 0) {
        result += (arg % 2) * i;
        arg = arg / 2;
        i = i * 10;
    }
    my_put_nbr(result);
}

void flag_x(va_list list)
{
    int arg = va_arg(list, int);
    argx(arg);
}

void argx(int arg)
{
    if (arg >= 16)
        argx(arg / 16);
    my_putchar("0123456789abcdef"[arg % 16]);
}
