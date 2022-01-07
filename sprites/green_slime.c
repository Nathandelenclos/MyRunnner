/*
** EPITECH PROJECT, 2021
** MyHunter
** File description:
** sprite
*/

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
#include <stdlib.h>

void green_slime_action(game_obj *obj, data *d)
{
    sfSprite_move(obj->sprite, obj->vector);
}

void green_slime_animate(game_obj *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->seconds = obj->time.microseconds / 1000000.0;
    if (obj->seconds >= 1 / 30) {
        if (obj->rect.left == 0)
            obj->rect.left = 376 * 29;
        else
            obj->rect.left -= 376;
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        sfVector2f scale = {0.5, 0.5};
        sfSprite_setScale(obj->sprite, scale);
        sfClock_restart(obj->clock);
    }
}

void create_green_slime(data *d, int width, int height)
{
    int size = 256;
    sfIntRect rect = create_rect(376 * 30, size, 0, 0);
    sfVector2f vector = {-6, 0};
    sfVector2f
        pos = {128 * (width), (128 * (height) + 30)};
    game_obj
        *obj =
        create_obj("./Assets/SlimeGreen/spritesheet.png", rect,
            pos, vector);
    set_scale(d, obj->sprite, 0.5);
    obj->rect = create_rect(376, 256, 376 * 29, 0);
    sfSprite_setTextureRect(obj->sprite, rect);
    obj->animated_frame = 30;
    obj->animate = green_slime_animate;
    obj->action = green_slime_action;
    obj->grp = MAP;
    sfRenderWindow_drawSprite(d->window, obj->sprite, NULL);
    put_in_list(&d->objs, obj);
}