/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** create hero
*/

#include "../include/list.h"
#include "../include/runner.h"
#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

void animate(game_obj *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->seconds = obj->time.microseconds / 1000000.0;
    float time = 0.11;
    if (obj->rect.top == 35 + 80 + 80)
        time = 0.15;
    if (obj->seconds > time) {
        obj->rect.left += 100;
        if (obj->rect.left >= 800 && obj->rect.top == 35 + 80 + 80)
            obj->rect.top = 35 + 80;
        if (obj->rect.left >= 800)
            obj->rect.left = 30;
        sfClock_restart(obj->clock);
        sfSprite_setTextureRect(obj->sprite, obj->rect);
    }
}

void action(game_obj *obj, data *d)
{
    sfVector2f down = {0, 6};
    if (sfSprite_getPosition(obj->sprite).y <= d->mode.height - 210)
        sfSprite_move(obj->sprite, down);
}

void create_hero(data *d)
{
    sfIntRect rect = create_rect(800, 240, 0, 0);
    sfVector2f pos = {100, d->mode.height - 210};
    sfVector2f vector = {0, 0};
    char filename[21] = "./resources/Hero.png";
    game_obj *hero = create_obj(filename, rect, pos, vector);
    set_scale(d, hero->sprite, 3.5);
    hero->animate = animate;
    hero->action = action;
    hero->rect = create_rect(45, 43, 30, 35 + 80);
    hero->grp = HERO;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->window, hero->sprite, NULL);
    put_in_list(&d->objs, hero);
}