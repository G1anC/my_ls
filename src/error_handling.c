/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** error_handling
*/

#include "../include/my.h"


extern void error_handler_explanations(char **av)
{
    // la gestion d'erreur vaut toujours entre 10 et 30 voir 40% du projet donc fais attention

    // on initialise une structure stat qui est une lib qui nous permet d'avoir pleins 
    // d'infos sur un fichier t'en auras vachement besoin pendant l'année

    struct stat inf;

    for (int i = 0; av[i]; i++) {

        // si il y a juste un '-' ou que q'ils mettent genre -abcdefghijklmnopqrstuvwxyz

        if (av[i][0] == '-' && (my_strlen(av[i]) < 2 || my_strlen(av[i]) > 7))

            // fonction a mettre dans ta lib qui exit 84 avec un message d'erreur dans le stderr

            exit_error("Invalid flag\n");

        // si il y a pas de '-' (donc dossier) mais qu'il existe pas

        if (av[i][0] != '-' && stat(av[i], &inf) == -1)

            // mauvais dossier

            exit_error("Invalid folder\n");

        // on boucle dans les flags, si un est invalide on exit

        for (int x = 1; av[i][x] != '\0'; x++)

            // biensur on fait ça avec un ternaire de ZINZIN parce qu'on est des boss

            (av[i][0] == '-') &&
            (av[i][x] != 'a' &&
            av[i][x] != 'l' &&
            av[i][x] != 'R' &&
            av[i][x] != 'd' &&
            av[i][x] != 'r' &&
            av[i][x] != 't') ?
            exit_error("Invalid flag\n") : 0;
    }
    // aucune erreur détectée let's gooo pour le code
}

extern void error_handler(char **av)
{
    struct stat inf;

    for (int i = 0; av[i]; i++) {
        if (av[i][0] == '-' && (my_strlen(av[i]) < 2 || my_strlen(av[i]) > 7))
            exit_error("Invalid flag\n");
        if (av[i][0] != '-' && stat(av[i], &inf) == -1)
            exit_error("Invalid folder\n");
        for (int x = 1; av[i][x] != '\0'; x++)
            (av[i][0] == '-') &&
            (av[i][x] != 'a' &&
            av[i][x] != 'l' &&
            av[i][x] != 'R' &&
            av[i][x] != 'd' &&
            av[i][x] != 'r' &&
            av[i][x] != 't') ?
            exit_error("Invalid flag\n") : 0;
    }
}