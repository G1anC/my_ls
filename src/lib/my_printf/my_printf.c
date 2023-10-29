/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** sus
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

void tableau_flags_fonctions(char c, va_list list)
{
    char flags[11] = {'c', 's', 'i', 'd', '%', 'o', 'x', 'b', 'X', 'u'};
    void (*fonctions[11])(va_list) = {flag_c, flag_s, flag_i, flag_d,
            flag_pourcent,flag_o, flag_x, flag_b, flag_x_maj, flag_u};

    for (int x = 0; flags[x]; x++)
        if (c == flags[x])
            (*fonctions[x])(list);
}

int my_printf(char const *str, ...)
{
    int i = 0;
    va_list list;
    va_start(list, *str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            tableau_flags_fonctions(str[++i], list);
            continue;
        } my_putchar(str[i]);
    } va_end(list);
    return 0;
}
