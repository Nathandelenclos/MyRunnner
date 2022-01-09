/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** print unprint
*/

#include "my.h"

void unprint(char *string) {

    char buff[4];
    for (int i = 0; i < my_strlen(string); ++i) {
        if (string[i] <= 32 || string[i] == 127) {
            my_int_to_str(string[i], buff, 8);
            my_putstr(buff);
        }
        else
            my_putchar(string[i]);
    }
}