/*
** EPITECH PROJECT, 2023
** is_hexa.c
** File description:
** is_hexa
*/

int check_character(char *str)
{
    for (int i = 1; str[i] != '\0'; i++)
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') &&
            (str[i] < '0' || str[i] > '9'))
            return 84;
    return 0;
}

int is_printable(char **array)
{
    for (int i = 0; array[i]; i++)
        if (check_character(array[i]))
            return 84;
    return 0;
}
