/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** create background
*/

#include "../include/my.h"
#include "../include/list.h"
#include "../include/runner.h"
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

void background_action(game_obj *obj)
{
    sfSprite_move(obj->sprite, obj->vector);
    sfVector2f v = sfSprite_getScale(obj->sprite);
    sfVector2f p = sfSprite_getPosition(obj->sprite);
    sfVector2f new_pos = {(512 * v.x), 0};
    if (p.x <= -(512 * v.x))
        sfSprite_setPosition(obj->sprite, new_pos);
}

void create_background(data *d)
{
    sfIntRect rect = create_rect(512, 256, 0, 0);
    float multiplier = (float) d->mode.height / rect.height;
    sfVector2f pos[2] = {{0, 0}, {(512 * multiplier), 0}};
    sfVector2f vector = {-7, 0};
    for (int i = 1; i < 6; ++i) {
        char filename[29] = "./resources/Background06.png";
        filename[28 - 5] -= i;
        vector.x++;
        for (int j = 0; j < 2; ++j) {
            game_obj *bg = create_obj(filename, rect, pos[j], vector);
            bg->grp = BACKGROUND;
            bg->action = background_action;
            sfRenderWindow_drawSprite(d->window, bg->sprite, NULL);
            set_scale(d, bg->sprite, (float) d->mode.height / bg->rect.height);
            put_in_list(&d->objs, bg);
        }
    }
}
