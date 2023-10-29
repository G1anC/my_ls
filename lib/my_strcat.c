/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** description
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest), i = 0;

    for (i; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
