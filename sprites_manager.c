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
    char *filename, sfIntRect rect, sfVector2f position, sfVector2f vector
)
{
    game_obj *obj = malloc(sizeof(game_obj));
    if (filename != NULL)
        obj->texture = sfTexture_createFromFile(filename, &rect);
    obj->sprite = sfSprite_create();
    obj->rect = rect;
    obj->clock = sfClock_create();
    obj->texture_file = my_strdup(filename);
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
    int cond1 = 0;
    int x = 0;
    int y = 0;
    while (tmp != NULL) {
        obj = (game_obj *)tmp->data;
        x = sfSprite_getPosition(obj->sprite).x;
        y = sfSprite_getPosition(obj->sprite).y;
        //if ((x > 0 && x < d->mode.width && y > 0 && y < d->mode.height) || obj->grp == BACKGROUND)
        sfRenderWindow_drawSprite(d->window, obj->sprite, NULL);
        tmp = tmp->next;
    }
}