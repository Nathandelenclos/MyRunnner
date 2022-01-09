/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** create hero
*/

#include "../include/list.h"
#include "../include/runner.h"
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

void animate(game_obj *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->seconds = obj->time.microseconds / 1000000.0;
    if (obj->seconds >= 0.025) {
        obj->texture->animate(obj);
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        sfVector2f scale = {0.70, 0.70};
        sfSprite_setScale(obj->sprite, scale);
        sfClock_restart(obj->clock);
    }
}

node *hero_is_on(data *d, enum group grp)
{
    node *tmp = d->objs;
    game_obj *tmp_obj = NULL;
    node *ret = NULL;
    while (tmp != NULL) {
        tmp_obj = (game_obj *) tmp->data;
        if (tmp_obj->grp == grp &&
            (int) (d->scrolling / 128) == (int) (tmp_obj->position.x / 128))
            put_in_list(&ret, tmp_obj);
        tmp = tmp->next;
    }
    return ret;
}

sfVector2f hero_fall(game_obj *obj, data *d, sfVector2f position)
{
    sfVector2f down = {0, 5};
    node *is_on = hero_is_on(d, MAP);
    node *tmp = is_on;
    game_obj *tmp_obj = NULL;
    int position_hero_y = position.y + obj->rect.height / 2;
    while (tmp != NULL) {
        tmp_obj = (game_obj *) tmp->data;
        if (position_hero_y <= tmp_obj->position.y + 10 &&
            position_hero_y >= tmp_obj->position.y - 10) {
            down.y = 0;
            obj->up = 2;
            return down;
        }
        tmp = tmp->next;
    }
    return down;
}

void action(game_obj *obj, data *d)
{
    sfVector2f position = sfSprite_getPosition(obj->sprite);
    sfSprite_move(obj->sprite, hero_fall(obj, d, position));
    if (position.y > d->mode.height) {
        d->hub->state = DEATH;
    }
}

void create_hero(data *d)
{
    sfVector2f vector[2] = {{100, 0}, {0, 0}};
    sfIntRect rect = create_rect(512, 512, 512 * 19, 0);
    game_obj *hero = create_obj(d, "hero", rect, vector);
    set_scale(d, hero->sprite, 0.5);
    hero->animate = animate;
    hero->action = action;
    hero->grp = HERO;
    hero->animated_frame = 20;
    hero->up = 2;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->window, hero->sprite, NULL);
    put_in_list(&d->objs, hero);
}