/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** description
*/

#include <stdlib.h>
#include "../include/my.h"

int my_strlen(char *str)
{
    int count = 0;

    if (!str)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    } return count;
}
