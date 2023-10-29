/*
** EPITECH PROJECT, 2023
** arrlen.c
** File description:
** arrlen
*/

#include "../include/my.h"

int arrlen(char **array)
{
    int i = 0;

    if (array == NULL)
        return 0;
    for (; array[i] != NULL; i++);
    return i;
}
