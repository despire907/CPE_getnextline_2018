/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#ifndef EPITECH_PROJECT_GET_NEXT_LINE_H
#define EPITECH_PROJECT_GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef READ_SIZE
#define READ_SIZE (128)
#endif

int my_strlen(char const *str);
int my_put_line(int fd, char *buff, int red);
char *my_realloc(char *str);
char *get_next_line(int fd);

#endif //EPITECH_PROJECT_GET_NEXT_LINE_H
