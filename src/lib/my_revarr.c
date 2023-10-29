/*
** EPITECH PROJECT, 2023
** my_revarr.c
** File description:
** my_revarr
*/

#include "../include/my.h"

char **my_revarr(char **arr)
{
    int i, j;
    char **new_arr = malloc(sizeof(char *) * (my_arrlen(arr) + 1));

    for (i = arrlen(arr) - 1, j = 0; arr[i]; i--, j++)
        new_arr[j] = my_strdup(arr[i]);
    new_arr[j] = NULL;
    return (new_arr);
}