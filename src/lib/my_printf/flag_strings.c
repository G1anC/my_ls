/*
** EPITECH PROJECT, 2022
** flag_strings.c
** File description:
** sus
*/

#include <stdlib.h>
#include <stdarg.h>
#include "../../include/my.h"

void flag_s(va_list list)
{
    my_putstr(1, va_arg(list, char*));
}

void flag_c(va_list list)
{
    my_putchar(va_arg(list, int));
}

void flag_pourcent(va_list list)
{
    my_putchar('%');
}
