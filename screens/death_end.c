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

void events_death(data *d, sfEvent event)
{
    game_obj *btn;
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->window);
        break;
    case sfEvtMouseButtonPressed:
        btn = is_on_btn(d, event.mouseButton);
        if (btn && my_strcmp(btn->name, "exit")) {
            sfRenderWindow_close(d->window);
        }
    }
}

void death_screen(struct data_s *data, sfEvent event)
{
    sfRenderWindow_clear(data->window, sfBlack);
    while (sfRenderWindow_pollEvent(data->window, &event))
        events_death(data, event);
    sprites_manager(data);
    text_manager(data);
    sfRenderWindow_display(data->window);
}

void create_data_death(data *d)
{
    create_widget_texture(d);
    create_btn(d, d->mode.width / 3, (d->mode.height / 2) + 70, "exit");
    sfVector2f scale = {1, 1};
    sfVector2f position = {d->mode.width / 3 + 20, d->mode.height / 2 + 70};
    put_in_list(&d->texts, create_text("EXIT", sfWhite, position, scale));
    position.y = (d->mode.height / 4) + 50;
    position.x = (d->mode.width / 3.5) + 40;
    scale.y = 3;
    scale.x = 3;
    put_in_list(&d->texts, create_text("You are dead !", sfBlack, position, scale));
    create_background_textures(d);
    create_background(d);
}

void *data_death(
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
    d->state = DEATH;
    d->window = window;
    d->font = sfFont_createFromFile("Assets/BuyanForest-Yz0jy.ttf");
    d->screen = death_screen;
    create_data_death(d);
    put_in_list(&screen1->datas, d);
}