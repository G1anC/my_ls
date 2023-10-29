/*
** EPITECH PROJECT, 2023
** single.c
** File description:
** main
*/

#include "../../include/my.h"

void one_folder_explanations(ls_t *ls, char *folder)
{
    struct dirent *x;
    DIR *fd = NULL;
    char **arr =malloc(sizeof(char *) * 1000);

    if (ls->dir) {

        //print le dossier actuel

        printf("%s\n", (folder) ? folder : ".");

        //toujours fermé le file descriptor qu'on ouvre

        exit(0);
    }
    fd = opendir(folder);
    while ((x = readdir(fd))) { 

        // print tous les fichiers mais cachés si -a

        if (ls->hid) {
            my_printf("%s\n", x->d_name);

            // continue = finir la boucle et passer à la suivante

            continue;

        // ls normal

        } if (x->d_name[0] != '.')
            my_printf("%s\n", x->d_name);
    }
    exit(closedir(fd));
}

void one_folder(ls_t *ls, char *folder)
{
    struct dirent *x;
    DIR *fd = NULL;
    char **arr =malloc(sizeof(char *) * 1000);

    if (ls->dir) {
        printf("%s\n", (folder) ? folder : ".");
        exit(0);
    }
    fd = opendir(folder);
    while ((x = readdir(fd))) {
        if (ls->hid) {
            my_printf("%s\n", x->d_name);
            continue;
        }
        if (x->d_name[0] != '.')
            my_printf("%s\n", x->d_name);
    } exit(closedir(fd));
}
