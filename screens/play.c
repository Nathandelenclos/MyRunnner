/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Screen
*/

#include "../include/my.h"
#include "../include/runner.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>

void play_screen(struct data_s *data, sfEvent event)
{
    sfRenderWindow_clear(data->window, sfBlack);
    while (sfRenderWindow_pollEvent(data->window, &event))
        event_manager(data, event);
    move_manager(data);
    time_manager(data);
    sprites_manager(data);
    text_manager(data);
    sfRenderWindow_display(data->window);
}

void create_data_play(data *d, char *filename)
{
    create_textures(d);
    create_hero(d);
    create_texts(d);
    map_manager(filename, d);
    sound_manager(d);
    create_background(d);
}

void *data_play(
    screen *screen1, char *filename, sfRenderWindow *window, sfVideoMode mode
)
{
    data *d = malloc(sizeof(data));
    d->objs = NULL;
    d->texts = NULL;
    d->sounds = NULL;
    d->textures = NULL;
    d->mode = mode;
    d->hub = screen1;
    d->state = PLAY;
    d->window = window;
    d->font = sfFont_createFromFile("resources/font.ttf");
    d->scrolling = 250;
    d->screen = play_screen;
    d->filemap = filename;
    create_data_play(d, filename);
    put_in_list(&screen1->datas, d);
}