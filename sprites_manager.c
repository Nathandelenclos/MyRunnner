/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** main manager sprites
*/

#include "include/list.h"
#include "include/runner.h"
#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

game_obj *create_obj(
    char *filename, sfIntRect rect, sfVector2f position, sfVector2f vector
)
{
    game_obj *obj = malloc(sizeof(game_obj));
    if (filename != NULL)
        obj->texture = sfTexture_createFromFile(filename, &rect);
    obj->sprite = sfSprite_create();
    obj->rect = rect;
    obj->clock = sfClock_create();
    obj->position = position;
    obj->vector = vector;
    obj->action = NULL;
    obj->animate = NULL;
    sfSprite_setPosition(obj->sprite, position);
    if (filename != NULL)
        sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
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