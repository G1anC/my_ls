/*
** EPITECH PROJECT, 2022
** strncmp.c
** File description:
** lol
*/

#include "../include/my.h"

int my_strncmp(char const *s1, char const *s2, int nb)
{
    int g;
    int diff;
    for (g = 0; s1[g] != '\0' && s2[g] != '\0' && s1[g] == s2[g]; g++)
        if (g >= nb - 1)
            break;
    diff = s1[g] - s2[g];
    return diff;
}
