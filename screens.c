/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** screens of myrunner 
*/

#include "include/my.h"
#include "include/runner.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

void play_screen(struct data_s *data, sfEvent event)
{
    sfRenderWindow_clear(data->window, sfBlack);
    while (sfRenderWindow_pollEvent(data->window, &event))
        event_manager(data, event);
    move_manager(data);
    time_manager(data);
    sprites_manager(data);
    sfRenderWindow_display(data->window);
}

void start_screen(struct data_s *data, sfEvent event)
{
    sfRenderWindow_clear(data->window, sfBlack);
    while (sfRenderWindow_pollEvent(data->window, &event))
        event_manager(data, event);
    move_manager(data);
    time_manager(data);
    sprites_manager(data);
    sfRenderWindow_display(data->window);
}