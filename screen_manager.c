/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Manager
*/

#include "include/runner.h"
#include "include/my.h"
#include <SFML/Graphics.h>

void screen_manager(
    screen *s, char *filename, sfRenderWindow *window, sfVideoMode mode
)
{
    data_start(s, my_strdup(filename), window, mode);
    data_play(s, my_strdup(filename), window, mode);
    data_death(s, my_strdup(filename), window, mode);
    data_win(s, my_strdup(filename), window, mode);
    data_pause(s, my_strdup(filename), window, mode);
}