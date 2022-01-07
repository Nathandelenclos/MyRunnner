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
        if (obj->rect.left == 0) {
            obj->animated_frame = 20;
            sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
            obj->rect.left = 512 * 19;
        } else {
            obj->rect.left -= 512;
        }
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        sfVector2f scale = {0.70, 0.70};
        sfSprite_setScale(obj->sprite, scale);
        sfClock_restart(obj->clock);
    }
}

game_obj *hero_is_on(data *d)
{
    node *tmp = d->objs;
    game_obj *tmp_obj = NULL;
    game_obj *ret = 0;
    while (tmp != NULL) {
        tmp_obj = (game_obj *) tmp->data;
        if (tmp_obj->grp == MAP &&
            (int) (d->scrolling / 128) == (int) (tmp_obj->position.x / 128))
            ret = tmp_obj;
        tmp = tmp->next;
    }
    return ret;
}

void action(game_obj *obj, data *d)
{
    sfVector2f down = {0, 5};
    game_obj *is_on = hero_is_on(d);
    sfVector2f position = sfSprite_getPosition(obj->sprite);
    if (!is_on || is_on->position.y > (position.y + obj->rect.height / 2) ||
        is_on->position.y + 128 < position.y)
        sfSprite_move(obj->sprite, down);
    else
        obj->up = 1;
}

void create_hero(data *d)
{
    sfIntRect rect = create_rect(10240, 512, 0, 0);
    sfVector2f pos = {100, 0};
    sfVector2f vector = {0, 0};
    char filename[60] =
        "./Assets/BlueWizard/2BlueWizardWalk/spritesheet.png";
    game_obj *hero = create_obj(filename, rect, pos, vector);
    set_scale(d, hero->sprite, 0.5);
    hero->rect = create_rect(512, 512, 512 * 19, 0);
    hero->animate = animate;
    hero->action = action;
    hero->grp = HERO;
    hero->animated_frame = 20;
    hero->up = 1;
    sfSprite_setTextureRect(hero->sprite, hero->rect);
    sfRenderWindow_drawSprite(d->window, hero->sprite, NULL);
    put_in_list(&d->objs, hero);
}