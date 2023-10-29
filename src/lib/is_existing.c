/*
** EPITECH PROJECT, 2023
** is_existing.c
** File description:
** is_existing
*/

#include "../include/my.h"

int is_existing(char *str, char c)
{
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}
