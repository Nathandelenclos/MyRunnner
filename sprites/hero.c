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
#include <SFML/System.h>
#include <SFML/Graphics.h>

void animate(game_obj *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->seconds = obj->time.microseconds / 1000000.0;
    char *filename = my_strdup(obj->texture_file);
    if (filename[my_strlen(filename) - 5] == '9') {
        filename[my_strlen(filename) - 5] = '0';
        if (filename[my_strlen(filename) - 6] == '1')
            filename[my_strlen(filename) - 6] = '0';
        else
            filename[my_strlen(filename) - 6] = '1';
    } else {
        filename[my_strlen(filename) - 5] += 1;
    }
    if (obj->seconds >= 0.025) {
        sfTexture *new = sfTexture_createFromFile(filename, &obj->rect);
        obj->texture_file = filename;
        sfSprite_setTexture(obj->sprite, new, sfTrue);
        sfVector2f scale = {0.70, 0.70};
        sfSprite_setScale(obj->sprite, scale);
        sfClock_restart(obj->clock);
    }
}

void action(game_obj *obj, data *d)
{
    sfVector2f down = {0, 6};
    if (sfSprite_getPosition(obj->sprite).y <= d->mode.height - 512) {
        sfSprite_move(obj->sprite, down);
    }

}

void create_hero(data *d)
{
    sfIntRect rect = create_rect(512, 512, 0, 0);
    sfVector2f pos = {100, d->mode.height - 430};
    sfVector2f vector = {0, 0};
    char filename[60] =
        "./Assets/BlueWizard/2BlueWizardWalk/Chara_BlueWalk00000.png";
    game_obj *hero = create_obj(filename, rect, pos, vector);
    set_scale(d, hero->sprite, 3.5);
    hero->animate = animate;
    hero->action = action;
    hero->grp = HERO;
    sfRenderWindow_drawSprite(d->window, hero->sprite, NULL);
    put_in_list(&d->objs, hero);
}