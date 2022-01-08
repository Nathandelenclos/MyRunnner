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
        obj->texture->animate(obj);
        sfVector2f scale = {0.4, 0.4};
        sfSprite_setScale(obj->sprite, scale);
        sfClock_restart(obj->clock);
    }
}

void create_green_slime(data *d, int width, int height)
{
    sfIntRect rect = create_rect(376, 256, 376 * 29, 0);
    sfVector2f vector = {-6, 0};
    sfVector2f pos = {128 * (width), (128 * (height) + 55)};
    sfVector2f v[2] = {pos, vector};
    game_obj *obj = create_obj(d, "green slime", rect, v);
    set_scale(d, obj->sprite, 0.4);
    obj->animated_frame = 30;
    obj->animate = green_slime_animate;
    obj->action = green_slime_action;
    obj->grp = ENEMY;
    sfRenderWindow_drawSprite(d->window, obj->sprite, NULL);
    put_in_list(&d->objs, obj);
}