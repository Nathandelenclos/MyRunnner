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

void create_btn(data *d, float x, float y, char *name)
{
    sfIntRect rect = create_rect(198, 60 / 3, 1, 1);
    sfVector2f vector = {0, 0};
    sfVector2f pos = {x, y};
    sfVector2f v[2] = {pos, vector};
    game_obj *obj = create_obj(d, "widget", rect, v);
    obj->grp = WIDGET;
    obj->name = name;
    set_scale(d, obj->sprite, 2.5);
    put_in_list(&d->objs, obj);
}