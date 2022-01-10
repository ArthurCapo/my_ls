/*
** EPITECH PROJECT, 2020
** muls
** File description:
** projet
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include "include/my.h"

char *arg(int ac, char **av)
{
    struct stat sb;
    char *path;
    int c = 0;
    for(int i = 1; i < ac; i++) {
        stat(av[i], &sb);
        if (S_ISDIR(sb.st_mode)) {
            path = malloc(sizeof(char) * my_strlen(av[i]));
            for(int j = 0; j < my_strlen(av[i]); path[j] = av[i][j], j++);
            c++;
        }
    }
    if (c == 0){
        path = malloc(sizeof(char) * 2);
        path[1] = '\0';
        path[0] = '.';
    }
    return (path);
}

void my_ls(char *path, char **argv)
{
    struct dirent *dirent;
    DIR *dir;
    dir = opendir(path);
    dirent = readdir(dir);

    while (dirent != NULL){
        if (dirent->d_name[0] != '.') {
            my_printf("%s\n", dirent->d_name);
        }
        dirent = readdir(dir);
    }
    closedir(dir);
}

void flag_d(int ac, char **av)
{
    if (ac == 2) {
        my_printf(".\n");
    } else
        my_printf("%s\n", av[2]);
}

void flag_l(char *path, char **argv)
{
    struct stat sb;
    struct dirent *dirent;
    struct passwd *pass;
    struct group *grp;
    DIR *dir;
    dir = opendir(path);
    dirent = readdir(dir);
    stat(dirent->d_name, &sb);
    my_printf("Total : %d\n", sb.st_blocks);

    while (dirent != NULL){
        if (dirent->d_name[0] != '.') {    
            stat(dirent->d_name, &sb);
            pass = getpwuid(sb.st_uid);
            grp = getgrgid(sb.st_gid);
            my_printf("%d %s %s ", sb.st_nlink,pass->pw_name, grp->gr_name);
            my_printf("%d ",sb.st_size);    
            my_printf("%s\n", dirent->d_name);
        }
        dirent = readdir(dir);
    }
    closedir(dir);
}

int main(int ac, char **av)
{
    char *path;
    path = arg(ac, av);
    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'd'){
        flag_d(ac, av);
    } else if (ac > 1 && av[1][0] == '-' && av[1][1] == 'l') {
        flag_l(path, av);
    } else {
        my_ls(path,av);
    }
}