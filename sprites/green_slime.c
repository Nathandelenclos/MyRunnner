/*
** EPITECH PROJECT, 2021
** MyHunter
** File description:
** sprite
*/

#include "../include/list.h"
#include "../include/runner.h"
#include "../include/my.h"
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

int hero_collide(data *d, game_obj *hero, node *mobs_x)
{
    node *tmp = mobs_x;
    game_obj *tmp_obj = NULL;
    int position_hero_y =
        sfSprite_getPosition(hero->sprite).y + hero->rect.height / 2;
    while (tmp != NULL) {
        tmp_obj = (game_obj *) tmp->data;
        if (position_hero_y <= tmp_obj->position.y + (tmp_obj->rect.height * 0.4) &&
            position_hero_y >= tmp_obj->position.y) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void green_slime_action(game_obj *obj, data *d)
{
    sfSprite_move(obj->sprite, obj->vector);
    if (hero_collide(d, get_hero(d), hero_is_on(d, ENEMY))) {
        my_printf("bonsoir oui");
        sfRenderWindow_close(d->window);
    }
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