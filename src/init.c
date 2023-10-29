/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** init
*/

#include "../include/my.h"

ls_t *check_flag_explanations(ls_t *ls, char *str)
{
    // on attribue les spécifités du ls en fonction des flags qui sont stockés dans str

    for (int i = 0; str[i]; i++) {

            // montres les fichiers cachés (a pour all)

        if (str[i] == 'a') ls->hid = true;

            // montres les infos des fichiers (l pour long)

        if (str[i] == 'l') ls->all = true;

            // montres les fichiers récursivement (R pour recursive)

        if (str[i] == 'R') ls->Rec = true;

            // montres les dossiers (d pour directory)

        if (str[i] == 'd') ls->dir = true;

            // montres les fichiers à l'envers (r pour reverse)

        if (str[i] == 'r') ls->rev = true;

            // montres les fichiers par date (t pour time)

        if (str[i] == 't') ls->time = true;

    } 
    // si c'est pas des vrais c'est des faux

    ls->hid = (ls->hid) ? true : false;
    ls->all = (ls->all) ? true : false;
    ls->Rec = (ls->Rec) ? true : false;
    ls->dir = (ls->dir) ? true : false;
    ls->rev = (ls->rev) ? true : false;
    ls->time = (ls->time) ? true : false;
    return ls;
}

ls_t *check_flag(ls_t *ls, char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'a') ls->hid = true;
        if (str[i] == 'l') ls->all = true;
        if (str[i] == 'R') ls->Rec = true;
        if (str[i] == 'd') ls->dir = true;
        if (str[i] == 'r') ls->rev = true;
        if (str[i] == 't') ls->time = true;
    }
    ls->hid = (ls->hid) ? true : false;
    ls->all = (ls->all) ? true : false;
    ls->Rec = (ls->Rec) ? true : false;
    ls->dir = (ls->dir) ? true : false;
    ls->rev = (ls->rev) ? true : false;
    ls->time = (ls->time) ? true : false;
    return ls;
}






ls_t *init_struct_explanations(char **av)
{
    // voilà là il n'y a aucune erreur donc go tout stocker dans une structure
    // initialisation de la structure

    ls_t *ls = malloc(sizeof(ls_t));

    // string temporaire pour stocker les flags

    char *tmp;

    // nous sert a passer a la prochaine ligne lorsqu'on a rempli un dossier

    int x = 0;

    // sert a savoir si on a déjà stocké les flags

    int flag = 0;

    // allocation de la mémoire pour les flags et les dossiers

    ls->arg = malloc(sizeof(char) * 20);
    ls->folder = malloc(sizeof(char *) * 100);

    // on boucle dans les arguments

    for (int i = 0; av[i]; i++) {

        // pour éviter un segv on fait d'abord un strcpy pour remplir la string des premiers arguments 
        // car strcat segv quand la string est encore vide

        if(av[i][0] == '-' && flag == 0) {
            my_strcpy(ls->arg, &av[i][1]);

            // on passe le flag a 1 pour dire qu'on a déjà stocké les flags

            flag = 1;
            continue;
        }

        // plus qu'à strcat le reste

        if (av[i][0] == '-' && flag == 1) {
            tmp = my_strdup(&av[i][1]);
            my_strncat(ls->arg, tmp, my_strlen(tmp));
            continue;
        } 

        // si ce n'est pas un flag alors c'est un dossier et on le stock

        ls->folder[x++] = my_strdup(av[i]);
    } 

    // ne pas oublier de mettre le dernier argument à NULL pour boucler à l'intérieur (conditional jump) 

    ls->folder[x] = NULL;

    // après ce return on a toutes les infos dont on a besoin dans la structure

    return check_flag(ls, ls->arg);
}

ls_t *init_struct(char **av)
{
    ls_t *ls = malloc(sizeof(ls_t));
    int x = 0, flag = 0;
    char *tmp;

    ls->arg = malloc(sizeof(char) * 20);
    ls->folder = malloc(sizeof(char *) * 100);
    for (int i = 0; av[i]; i++) {
        if(av[i][0] == '-' && flag == 0) {
            my_strcpy(ls->arg, &av[i][1]);
            flag = 1;
            continue;
        } if (av[i][0] == '-' && flag == 1) {
            tmp = my_strdup(&av[i][1]);
            my_strncat(ls->arg, tmp, my_strlen(tmp));
            continue;
        } ls->folder[x++] = my_strdup(av[i]);
    } ls->folder[x] = NULL;
    return check_flag(ls, ls->arg);
}