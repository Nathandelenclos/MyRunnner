/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Sprite
*/

#include "../include/list.h"
#include "../include/runner.h"
#include "../include/my.h"
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void safe_platform_action(game_obj *obj, data *d)
{
    sfSprite_move(obj->sprite, obj->vector);
}

void create_safe_platform(data *d, int width, int height)
{
    int size = 2048;
    sfIntRect
        rect = create_rect(size / 4, size / 4, (size / 4) * 2, (size / 4) * 3);
    sfVector2f vector = {-6, 0};
    sfVector2f pos = {128 * (width), 128 * (height)};
    sfVector2f v[2] = {pos, vector};
    game_obj *obj = create_obj(d, "platform",rect, v);
    obj->grp = MAP;
    set_scale(d, obj->sprite, 0.25);
    obj->action = safe_platform_action;
    int r = rand() % 11;
    my_printf("r = %i\n", r);
    if (r == 5)
        create_green_slime(d, width, height - 1);
    put_in_list(&d->objs, obj);
}