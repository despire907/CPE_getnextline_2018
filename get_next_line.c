/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#include "get_next_line.h"

int my_strlen_until(char const *str)
{
    int bobo = 0;

    while (str[bobo] != '\0' && str[bobo] != '\n'){
        bobo = bobo + 1;
    }
    return (bobo);
}

static char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    } if (n < i)
        dest[i] = '\0';
    return dest;
}

static char *look_first_line(char *ptr, int j, char **buff, int *start)
{
    char *str = NULL;
    char *tmp = NULL;
    int i = 0;

    if (ptr != NULL) {
        i = my_strlen_until(ptr);
        if ((str = malloc(sizeof(str) * (i + j + 1))) == NULL)
            return NULL;
        my_strncpy(str, ptr, i);
    } else {
        if ((str = malloc(sizeof(str) * (i + j + 1))) == NULL)
            return NULL;
        my_strncpy(str, "", i);
    }
    str[i + j] = '\0';
    my_strncpy(str + i, *buff + *start, j);
    *start = *start + (j + 1);
    return str;
}

static char *check_end(char *ptr, int fd, char *buff, int *start)
{
    int i = 0;
    int j = 0;

    while (42) {
        if (*start >= i) {
            *start = 0;
            j = 0;
            if (!(i = read(fd, buff, 1)))
                return ptr;
            else if (i == -1)
                return NULL;
        } if (buff[*start + j] == '\n') {
            if ((ptr = look_first_line(ptr, j, &buff, start)) != NULL)
                return ptr;
            else
                return NULL;
        } if (*start + j == i - 1)
            if ((ptr = look_first_line(ptr, j + 1, &buff, start)) == NULL)
                return NULL;
        j++;
    }
}

char *get_next_line(int fd)
{
    static char buff[1];
    int start = 0;
    char *ptr = NULL;

    if ((ptr = check_end(ptr, fd, buff, &start)) == NULL)
        return NULL;
    else {
        return ptr;
    }
}