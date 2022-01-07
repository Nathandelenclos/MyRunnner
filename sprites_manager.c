/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** main manager sprites
*/

#include "include/list.h"
#include "include/runner.h"
#include "include/my.h"
#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

game_obj *create_obj(
    data *d, char *texture_name, sfIntRect rect, sfVector2f *vector)
{
    game_obj *obj = malloc(sizeof(game_obj));
    obj->texture = get_texture(d, texture_name);
    obj->sprite = sfSprite_create();
    obj->rect = rect;
    obj->clock = sfClock_create();
    obj->position = vector[0];
    obj->vector = vector[1];
    obj->action = NULL;
    obj->animate = NULL;
    sfSprite_setPosition(obj->sprite, vector[0]);
    sfSprite_setTexture(obj->sprite, obj->texture->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    return obj;
}

void set_scale(data *d, sfSprite *sprite, float multiplier)
{
    sfVector2f resize = {multiplier, multiplier};
    sfSprite_setScale(sprite, resize);
}

sfIntRect create_rect(int width, int height, int left, int top)
{
    sfIntRect rect;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    rect.top = top;
    return rect;
}

void sprites_manager(data *d)
{
    game_obj *obj;
    node *tmp = d->objs;
    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        sfRenderWindow_drawSprite(d->window, obj->sprite, NULL);
        tmp = tmp->next;
    }
}