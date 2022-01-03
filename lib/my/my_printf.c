/*                                                                              
** EPITECH PROJECT, 2021                                                        
** LIB                                                                      
** File description:                                                            
** printf                              
*/

#include <stdarg.h>
#include "my.h"

char *norme_octo(char *str, char *buff, int size)
{
    int size_str = my_strlen(str);
    int diff = size - size_str;

    for (int i = 0; i < diff; ++i)
        buff[i] = '0';
    for (int i = diff; i < size; ++i)
        buff[i] = str[i - diff];
    buff[size] = '\0';
    return buff;
}

void print_arg(char *string, int i, va_list vaList)
{
    switch (string[i + 1]) {
        case 'i': case 'o': case 'u':
            my_put_nbr((int)va_arg(vaList, int));
            break;
        case 's':
            my_putstr((char*) va_arg(vaList, char*));
            break;
        case 'S': {
            char* string = (char *)va_arg(vaList, char*);

            for (int i = 0; i < my_strlen(string); ++i) {
                int size = my_nbr_of_digit(string[i]) + 1;
                char buff[size];
                char buff2[4];
                if (string[i] <= 32 || string[i] == 127) {
                    my_int_to_str(string[i], buff, 8);
                    my_putstr(norme_octo(buff, buff2, 3));
                }
                else
                    my_putchar(string[i]);
            }

            break;
        }
        case 'c' | 'C':
            my_putchar((int) va_arg(vaList, int));
            break;
        case '%':
            my_putchar('%');
            break;
        case 'b': {
            int nb = (int)va_arg(vaList, int);
            int size = my_nbr_of_digit(nb) + 1;
            char buff[size];
            my_int_to_str(nb, buff, 2);
            my_putstr(buff);
            break;
        }
        default:
            my_error("Invalid type.");
            break;
    }
}

int my_printf(char *str, ...) {
    va_list vaList;
    va_start(vaList, str);
    for (int i = 0; i < my_strlen(str); ++i) {
        if (str[i] == '%') {
            print_arg(str, i, vaList);
            i++;
        }
        else
            my_putchar(str[i]);
    }
    va_end(vaList);
    return (1);
}