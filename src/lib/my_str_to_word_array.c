/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.C
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "../include/my.h"

static int nbr_of_ligns(char *str)
{
    int ligns = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i] == '\t') &&
            (str[i - 1] != ' ' || str[i - 1] != '\t'))
            ligns++;
    }
    return ligns;
}

static char** malloc_work(char *str)
{
    int ligns = nbr_of_ligns(str);
    char **array = 0;
    array = malloc(sizeof(char*) * (ligns + 1));
    for (int x = 0; x < (ligns); x++) {
        array[x] = malloc(sizeof(char) * 3000);
    }
    return array;
}

static int quote(char *str, int *q)
{
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\"') counter++;
    if (counter % 2 != 0) {
        my_putstr(1, "Unmatched '\"'.\n");
        return -1;
    } *q = (*q == 0) ? 1 : 0;
    return *q;
}

char **my_str_to_word_array(char *str)
{
    char **array = malloc_work(str);
    int row = 0, col = 0, q = 0;

    for (int n = 0; str[n] != '\0'; n++) {
        if (str[n] == '\"' && quote(str, &q) == -1) return (NULL);
        if (((str[n] == ' ' || str[n] == '\t') &&
            (n == 0 || str[n - 1] != ' ' || str[n - 1] == '\t')) && !q) {
            array[row++][col] = '\0';
            col = 0;
            continue;
        } if (((n == 0 || str[n - 1] == ' ' || str[n - 1] == '\t') &&
            (str[n] == ' ' || str[n] == '\t')) && !q) continue;
        array[row][col++] = str[n];
    } array[row][col] = '\0';
    array[row + 1] = NULL;
    return array;
}
