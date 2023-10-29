/*
** EPITECH PROJECT, 2023
** LS.h
** File description:
** LS2
*/

#include <sys/types.h>

#ifndef LS_H_
    #define LS_H_

        // P R O J E C T  I N C L U D E S

        #include <dirent.h>
        #include <sys/stat.h>
        #include <sys/types.h>
        #include <pwd.h>
        #include <grp.h>
        #include <time.h>
        #include <stdbool.h>

        //  S T R U C T U R E S

        typedef struct ls_s {
            char **folder;
            char *arg;
            bool Rec;
            bool hid;
            bool all;
            bool rev;
            bool dir;
            bool time;
        } ls_t;

        //  P R O J E C T  P R O T O T Y P E S

    extern ls_t *init_struct(char **av);
    extern void error_handler(char **av);
    extern void one_folder(ls_t *ls, char *folder);
    void print_all(const char *file, struct stat st);
    int ls_l(ls_t *ls);

#endif /* !LS2_H_ */
