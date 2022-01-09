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

game_obj *is_on_btn(data *d, sfMouseButtonEvent event)
{
    game_obj *obj;
    node *tmp = d->objs;
    sfVector2f position;
    sfVector2f scale;
    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        position = sfSprite_getPosition(obj->sprite);
        scale = sfSprite_getScale(obj->sprite);
        if (obj->grp == WIDGET && event.y > position.y &&
            event.y < position.y * scale.y && event.x > position.x &&
            event.x < position.x * scale.x)
            return obj;
        tmp = tmp->next;
    }
    return 0;
}

void events(data *d, sfEvent event)
{
    game_obj *btn;
    switch (event.type) {
    case sfEvtClosed:
        sfRenderWindow_close(d->window);
        break;
    case sfEvtMouseButtonPressed:
        btn = is_on_btn(d, event.mouseButton);
        if (btn && my_strcmp(btn->name, "play"))
            d->hub->state = PLAY;
        if (btn && my_strcmp(btn->name, "exit")) {
            sfRenderWindow_close(d->window);
        }
    }
}

void start_screen(struct data_s *data, sfEvent event)
{
    sfRenderWindow_clear(data->window, sfBlack);
    while (sfRenderWindow_pollEvent(data->window, &event))
        events(data, event);
    sprites_manager(data);
    text_manager(data);
    sfRenderWindow_display(data->window);
}

void create_data(data *d)
{
    create_widget_texture(d);
    create_btn(d, d->mode.width / 3, d->mode.height / 2, "play");
    create_btn(d, d->mode.width / 3, (d->mode.height / 2) + 70, "exit");
    sfVector2f scale = {1, 1};
    sfVector2f position = {d->mode.width / 3 + 20, d->mode.height / 2};
    put_in_list(&d->texts, create_text("PLAY", sfWhite, position, scale));
    position.y = d->mode.height / 2 + 70;
    put_in_list(&d->texts, create_text("EXIT", sfWhite, position, scale));
    position.y = d->mode.height / 4;
    position.x = d->mode.width / 3.5;
    scale.y = 5;
    scale.x = 5;
    put_in_list(&d->texts, create_text("MyRunner", sfBlack, position, scale));
    create_background_textures(d);
    create_background(d);
}

void *data_start(
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
    d->state = START;
    d->window = window;
    d->font = sfFont_createFromFile("Assets/BuyanForest-Yz0jy.ttf");
    d->screen = start_screen;
    create_data(d);
    put_in_list(&screen1->datas, d);
}