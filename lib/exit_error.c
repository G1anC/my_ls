/*
** EPITECH PROJECT, 2023
** exit_error.c
** File description:
** exit_error
*/

#include "../include/my.h"

void exit_error(char *str)
{
    write(2, str, my_strlen(str));
    exit(84);
}