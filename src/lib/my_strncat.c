/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** description
*/

#include "../include/my.h"

extern char *my_strncat(char *dest, char const *src, int nb)
{
    int len = my_strlen(dest), i = 0;

    for (; i < nb && src[i] != '\0'; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
