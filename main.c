/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "include/my.h"

static int ls_functions_explanations(DIR *fd, ls_t *ls)
{
    struct dirent *x;

    // crée un array dans lequel on met tous les fichiers du dossier
    
    char **array = malloc(sizeof(char *) * 100); // beurk
    int i = 0;


    while (x = readdir(fd)) {

        // si on a -a alors on stock tous les fichiers

        if (ls->hid) {
            array[i++] = my_strdup(x->d_name);
            continue;
        } 

        // sinon on stock tous les fichiers qui ne commencent pas par un .

        if (x->d_name[0] != '.')
            array[i++] = my_strdup(x->d_name);
    }

    // toujours fermé un tableau pour les erreurs valgrind

    array[i - 1] = NULL;

    // si on doit le reverse alors c'est parti

    if (ls->rev)
        my_revarr(array);

    // on a plus qu'a print tous les files

    for (int i = 0; array[i]; i++) {
        my_printf("  %s\n", array[i]);
    }
    return 0;
}

static int ls_functions(DIR *fd, ls_t *ls)
{
    struct dirent *x;
    char **array = malloc(sizeof(char *) * 100);
    int i = 0;

    while (x = readdir(fd)) {
        if (ls->hid) {
            array[i++] = my_strdup(x->d_name);
            continue;
        } if (x->d_name[0] != '.')
            array[i++] = my_strdup(x->d_name);
    } array[i - 1] = NULL;
    if (ls->rev)
        my_revarr(array);
    for (int i = 0; array[i]; i++) {
        my_printf("  %s\n", array[i]);
    } return 0;
}






static int core_explanations(ls_t *ls)
{
    // on définit la variable fd (file descriptor) dont on aura besoin (important pour les stumpers)

    DIR *fd = NULL;

    // on va le faire séparement parce que bon il est casse couilles

    if (ls->all)
        exit(ls_l(ls));

    // si 1 ou 0 dossier en argument

    if (arrlen(ls->folder) <= 1)

        // si on a un dossier en argument alors on le donne a one_folder sinon on lui donne le . (dossier actuel)

        (ls->folder[0]) ? one_folder(ls, ls->folder[0]) : one_folder(ls, ".");

    // sinon :

    // si il y a un -r on reverse le tableau de dossiers

    if (ls->rev)
        my_revarr(ls->folder);

    //on boucle sur les dossiers

    for (int i = 0; ls->folder[i]; i++) {

        // si en flag on a -d alors on print le dossier

        if (ls->dir) {
            my_printf("%s\n", ls->folder[i]);
            continue;
        }

        // sinon on ouvre le dossier

        fd = opendir(ls->folder[i]);

        // on print "nom du dossier :" 

        my_printf("%s:\n", ls->folder[i]);
        ls_functions(fd, ls);

        // on print un \n supplémentaire si un autre dossier suit

        if (ls->folder[i + 1])
            my_printf("\n");
        closedir(fd);
    } return 0;
}

static int core(ls_t *ls)
{
    DIR *fd = NULL;

    if (ls->all)
        exit(ls_l(ls));
    if (arrlen(ls->folder) <= 1)
        (ls->folder[0]) ? one_folder(ls, ls->folder[0]) : one_folder(ls, ".");
    if (ls->rev)
        my_revarr(ls->folder);
    for (int i = 0; ls->folder[i]; i++) {
        if (ls->dir) {
            my_printf("%s\n", ls->folder[i]);
            continue;
        } 
        fd = opendir(ls->folder[i]);
        my_printf("%s:\n", ls->folder[i]);
        ls_functions(fd, ls);
        if (ls->folder[i + 1])
            my_printf("\n");
        closedir(fd);
    } return 0;

}






int main(int ac, char **argv)
{
    ls_t *ls = NULL;
    char **av = &argv[1];

    error_handler(av);
    ls = init_struct(av);
    return core(ls);
}