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

void safe_platform_action(game_obj *obj, data *d)
{
    sfSprite_move(obj->sprite, obj->vector);
}

void create_safe_platform(data *d, int width, int height)
{
    int size = d->mode.height / 16;
    sfIntRect rect = create_rect(size, size, 10, 10);
    sfVector2f vector = {-6, 0};
    sfVector2f pos = {size * (width + 1), size * (height + 1)};
    game_obj
        *obj = create_obj("resources/square_blue.jpg", rect, pos, vector);
    obj->action = safe_platform_action;
    put_in_list(&d->objs, obj);
}