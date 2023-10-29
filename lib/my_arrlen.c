/*
** EPITECH PROJECT, 2023
** my_arrlen.c
** File description:
** my_arrlen
*/

#include <stdlib.h>

int my_arrlen(char **array)
{
    int i = 0;

    if (array == NULL)
        return 0;
    for (; array[i]; i++);
    return i;
}
