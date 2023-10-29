/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

extern char* my_strdup(char* str)
{
    return (!str) ? NULL : my_strcpy
    (malloc(sizeof(char) * my_strlen(str) + 1), str);
}
