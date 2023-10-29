/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** description
*/

#include "../include/my.h"

char *my_strncpy(char *dest, char *src, int size)
{
    int i = 0;
    for (; i < size; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
