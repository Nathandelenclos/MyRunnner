/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Manager
*/

#include "include/list.h"
#include "include/runner.h"
#include "include/my.h"
#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

void screen_manager(screen *s, char *filename, sfRenderWindow *window, sfVideoMode mode)
{
    data_start(s, my_strdup(filename), window, mode);
    data_play(s, my_strdup(filename), window, mode);
    data_death(s, my_strdup(filename), window, mode);
    data_win(s, my_strdup(filename), window, mode);
    data_pause(s, my_strdup(filename), window, mode);
}