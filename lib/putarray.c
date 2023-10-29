/*
** EPITECH PROJECT, 2023
** putarray.c
** File description:
** putarray
*/

#include "../include/my.h"

void putarray(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        write(1, array[i], my_strlen(array[i]));
        my_putchar('\n');
    }
}

void real_print_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
                my_printf("%c ", array[i][j]);
        }
        my_putchar('\n');
    }
}

void my_print_matrix(int **matrix, int y, int x)
{
    for (int i = 0; i < y; i++) {
        for (int j = 0; i < x; i++)
            my_printf("%d ", matrix[i][j]);
        my_printf(("\n"));
    }
}

void my_print_color(char **array)
{
    int g = 36;
    for (int i = 0; array[i]; i++, g++) {
        my_printf("\033[%d;01m%s\033[00m # ", g, array[i]);
        if (i % 2 == 0)
            g -= 2;
    }
    my_printf("\033[35;01m &>  \033[00m");
}
