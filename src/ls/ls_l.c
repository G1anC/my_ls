/*
** EPITECH PROJECT, 2023
** ls_l
** File description:
** ls_l
*/

#include "../../include/my.h"


void print_perm_explanations(mode_t mode)
{
    // je vais pas te le cacher ça a ChatGPT tout fort
    // mais du coup tous les S_I... c'est les permissions sur les dossiers
    // parce qu'il y a des fichiers que tu peux pas executer
    // des fichiers que tu ne peux pas lire
    // et des fichiers dans lesquels tu ne peux pas écrire 
    // r : read, w : write, x : execute

    // les 3 premiers c'est pour le user

    my_printf((S_ISDIR(mode)) ? "d" : "-");
    my_printf((mode & S_IRUSR) ? "r" : "-");
    my_printf((mode & S_IWUSR) ? "w" : "-");
    my_printf((mode & S_IXUSR) ? "x" : "-");

    // les 3 suivants c'est pour le groupe

    my_printf((mode & S_IRGRP) ? "r" : "-");
    my_printf((mode & S_IWGRP) ? "w" : "-");
    my_printf((mode & S_IXGRP) ? "x" : "-");

    // les 3 derniers c'est pour les autres

    my_printf((mode & S_IROTH) ? "r" : "-");
    my_printf((mode & S_IWOTH) ? "w" : "-");
    my_printf((mode & S_IXOTH) ? "x" : "-");
    my_printf(". ");
}

void print_perm(mode_t mode)
{
    my_printf((S_ISDIR(mode)) ? "d" : "-");
    my_printf((mode & S_IRUSR) ? "r" : "-");
    my_printf((mode & S_IWUSR) ? "w" : "-");
    my_printf((mode & S_IXUSR) ? "x" : "-");
    my_printf((mode & S_IRGRP) ? "r" : "-");
    my_printf((mode & S_IWGRP) ? "w" : "-");
    my_printf((mode & S_IXGRP) ? "x" : "-");
    my_printf((mode & S_IROTH) ? "r" : "-");
    my_printf((mode & S_IWOTH) ? "w" : "-");
    my_printf((mode & S_IXOTH) ? "x" : "-");
    my_printf(". ");
}






void print_all_explanations(const char *file, struct stat st)
{
    // on récupère les infos du user et du groupe

    struct passwd *pwd = getpwuid(st.st_uid);
    struct group *grp = getgrgid(st.st_gid);

    // print les permeissions

    print_perm(st.st_mode);

    // print les infos

    my_printf("%d %s ", st.st_nlink, pwd->pw_name);
	my_printf("%s %d ", grp->gr_name, st.st_size);

    // print la date de création du fichier (attention ça marche pas forcément très bien)
    // j'utilise write pour écrire des types que j'ai pas fait dans le my printf, genre une structure complète.

    write(1, (ctime(&st.st_mtime) + 4), \
			(my_strlen(ctime(&st.st_mtime)) - 13));
    my_printf(" %s\n", file);
}

void print_all(const char *file, struct stat st)
{
    struct passwd *pwd = getpwuid(st.st_uid);
    struct group *grp = getgrgid(st.st_gid);

    print_perm(st.st_mode);
    my_printf("%d %s ", st.st_nlink, pwd->pw_name);
	my_printf("%s %d ", grp->gr_name, st.st_size);
    write(1, (ctime(&st.st_mtime) + 4), \
			(my_strlen(ctime(&st.st_mtime)) - 13));
    my_printf(" %s\n", file);
}






static void one_folder_l_explanations(ls_t *ls, char *folder)
{
    struct dirent *x;
    DIR *fd = NULL;
    struct stat st;

    stat(folder, &st);
    fd = opendir(folder);

    // print le total de blocks

    if (!ls->dir)
        my_printf("total %d\n", st.st_blocks);
    while ((x = readdir(fd))) {
        if (ls->dir) {
            print_all(".", st);

            // on break parce qu'on vient rien d'autre même avec le -R

            break;

        // print tous les fichiers si -a

        } if (ls->hid)
            print_all(x->d_name, st);

        // sinon on print pas les fichiers cachés

        else
            (x->d_name[0] != '.') ? print_all(x->d_name, st) : 0;
    }  exit(closedir(fd));
}

static void one_folder_l(ls_t *ls, char *folder)
{
    struct dirent *x;
    DIR *fd = NULL;
    struct stat st;

    stat(folder, &st);
    fd = opendir(folder);
    if (!ls->dir)
        my_printf("total %d\n", st.st_blocks);
    while ((x = readdir(fd))) {
        if (ls->dir) {
            print_all(".", st);
            break;
        } 
        if (ls->hid)
            print_all(x->d_name, st);
        else
            (x->d_name[0] != '.') ? print_all(x->d_name, st) : 0;
    } exit(closedir(fd));
}






int ls_l_explanations(ls_t *ls)
{
    struct stat st;

    if (arrlen(ls->folder) <= 1)

        // si on a un dossier en argument alors on le donne a one_folder sinon on lui donne le . (dossier actuel)

        (ls->folder[0]) ? one_folder_l(ls, ls->folder[0]) : one_folder_l(ls, ".");
    
    // sinon :

    // on boucle sur les dossiers

    for (int i = 0; ls->folder[i]; i++) {

        // si en flag on a -d alors on print all des dossiers et non pas des fichiers

        if (ls->dir) {
            print_all(ls->folder[i], st);
            continue;
        }

        // sinon on print "nom du dossier :" 

        my_printf("%s:\n", ls->folder[i]);
        print_all(ls->folder[i], st);

        // on print un \n supplémentaire si un autre dossier suit

        if (ls->folder[i + 1])
            my_printf("\n");

    }
}

int ls_l(ls_t *ls)
{
    struct stat st;

    if (arrlen(ls->folder) <= 1)
        (ls->folder[0]) ? one_folder_l(ls, ls->folder[0]) : one_folder_l(ls, ".");
    for (int i = 0; ls->folder[i]; i++) {
        if (ls->dir) {
            print_all(ls->folder[i], st);
            continue;
        }
        my_printf("%s:\n", ls->folder[i]);
        print_all(ls->folder[i], st);
        if (ls->folder[i + 1])
            my_printf("\n");
    } return 0;
}