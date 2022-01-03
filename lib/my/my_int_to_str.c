/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** int to str
*/

#include "my.h"
#include <stdlib.h>

char *my_int_to_str(int value, char *buffer, int base)
{
    if (base < 2 || base > 32)
        return buffer;
    int n = value;
    if (value < 0)
        n = -value;
    int i = 0;
    while (n) {
        int r = n % base;
        if (r >= 10)
            buffer[i++] = 65 + (r - 10);
        else
            buffer[i++] = 48 + r;
        n = n / base;
    }
    if (i == 0)
        buffer[i++] = '0';
    if (value < 0 && base == 10)
        buffer[i++] = '-';
    buffer[i] = '\0';
    return my_revstr(buffer);
}