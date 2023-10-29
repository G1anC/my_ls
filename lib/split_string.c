/*
** EPITECH PROJECT, 2023
** split_string.c
** File description:
** split_string
*/

#include <stdlib.h>
#include "../include/my.h"

int nbr_of_ligns_ss(char const *str, char s)
{
    int ligns = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == s && str[i - 1] != s)
            ligns++;
    }
    return ligns;
}

char** malloc_work_ss(char const *str, char s)
{
    int ligns = nbr_of_ligns_ss(str, s);
    char **array = 0;
    array = malloc(sizeof(char*) * (ligns + 1));
    for (int x = 0; x < (ligns); x++) {
        array[x] = malloc(sizeof(char) * 3000);
    }
    return array;
}

char **split_string(char *str, char s)
{
    char **array = malloc_work_ss(str, s);
    int row = 0;
    int col = 0;

    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] == s && str[n - 1] != s) {
            array[row][col] = '\0';
            row++;
            col = 0;
            continue;
        }
        array[row][col++] = str[n];
    }
    array[row][col] = '\0';
    array[row + 1] = NULL;
    return array;
}
