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
    int size = 2048;
    sfIntRect rect = create_rect(size, size, 0, 0);
    sfVector2f vector = {-6, 0};
    sfVector2f
        pos = {(size / 4) / 4 * (width), (size / 4) / 4 * (height + 1)};
    game_obj
        *obj =
        create_obj("./Assets/Mossy Tileset/Mossy - FloatingPlatforms.png", rect,
            pos, vector);
    rect = create_rect(size / 4, size / 4, (size / 4) * 1.5, 0);
    set_scale(d, obj->sprite, 0.25);
    sfSprite_setTextureRect(obj->sprite, rect);
    obj->action = safe_platform_action;
    put_in_list(&d->objs, obj);
}