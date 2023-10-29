/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** my_revstr
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    int i = 0, j = my_strlen(str) - 1;
    char tmp;

    while (i < j) {
        tmp = str[i];
        str[i++] = str[j];
        str[j--] = tmp;
    } return (str);
}