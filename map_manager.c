/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Map manager
*/

#include "include/runner.h"
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

char *file_to_str(char *filename)
{
    int fd1 = open(filename, O_RDONLY);
    char *data;
    int size = 0;
    if (fd1 < 0 && errno == 2) {
        my_error("File can't open");
        return (0);
    }
    data = malloc(50000 + 1);
    size = read(fd1, data, 50000);
    if (size < 0)
        write(2, "An error occurred in the read.\n", 31);
    data[size] = '\0';
    if (close(fd1) < 0 && errno == 2) {
        my_error("File can't close");
        return (0);
    }
    return data;
}

void check_element(char c, data *d, int height, int width)
{
    switch (c) {
    case '1':
        create_safe_platform(d, width, height);
        break;
    case '2':
        create_safe_platform_right(d, width, height);
        break;
    case '3':
        create_safe_platform_left(d, width, height);
        break;
    case '4':
        create_green_slime(d, width, height);
        break;
    case 'v':
        create_end(d, width, height);
    }
}

void create_elements(char *string, data *d)
{
    int width = 0;
    int height = 0;
    for (int i = 0; i < my_strlen(string); ++i) {
        if (string[i] == '\n') {
            height++;
            width = 0;
        }
        check_element(string[i], d, height, width);
        width++;
    }
}

void map_manager(char *map_name, data *d)
{
    char *map = file_to_str(map_name);
    create_elements(map, d);
}