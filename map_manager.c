/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Map manager
*/

#include "include/list.h"
#include "include/runner.h"
#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
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

void create_elements(char *string, data *d)
{
    int index = 0;

    int width = 0;
    int height = 0;
    for (int i = 0; i < my_strlen(string); ++i) {
        if (string[i] == '\n') {
            height++;
            width = 0;
        }
        switch (string[i]) {
        case '1':
            create_safe_platform(d, width, height);
        case '2':
            create_enemy_platform(d, width, height);
        case '3':
            create_enemy_peak(d, width, height);
        }
        width++;
    }
}

void map_manager(char *map_name, data *d)
{
    char *map = file_to_str(map_name);
    create_elements(map, d);
}