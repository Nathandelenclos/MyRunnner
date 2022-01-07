/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Sprite
*/


#include "../include/list.h"
#include "../include/runner.h"
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdio.h>

void safe_platform_left_action(game_obj *obj, data *d)
{
    sfSprite_move(obj->sprite, obj->vector);
}

void create_safe_platform_left(data *d, int width, int height)
{
    int size = 2048;
    sfIntRect rect = create_rect(size / 4, size / 4, (size / 4) * 0, (size / 4) * 3);
    sfVector2f vector = {-6, 0};
    sfVector2f pos = {128 * (width), 128 * (height)};
    sfVector2f v[2] = {pos, vector};
    game_obj *obj = create_obj(d, "platform", rect,v);
    obj->grp = MAP;
    set_scale(d, obj->sprite, 0.25);
    obj->action = safe_platform_left_action;
    put_in_list(&d->objs, obj);
}