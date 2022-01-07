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

char *new_filename(char *string)
{
    char *filename = my_strdup(string);
    if (filename[my_strlen(filename) - 5] == '9') {
        filename[my_strlen(filename) - 5] = '0';
        if (filename[my_strlen(filename) - 6] == '1')
            filename[my_strlen(filename) - 6] = '0';
        else
            filename[my_strlen(filename) - 6] = '1';
    } else {
        filename[my_strlen(filename) - 5] += 1;
    }
    return filename;
}

void animate(game_obj *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->seconds = obj->time.microseconds / 1000000.0;
    if (obj->seconds >= 0.025) {
        char *filename = new_filename(obj->texture_file);
        sfTexture *new = sfTexture_createFromFile(filename, &obj->rect);
        free(obj->texture_file);
        obj->texture_file = filename;
        sfSprite_setTexture(obj->sprite, new, sfTrue);
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
    sfVector2f down = {0, 10};
    game_obj *is_on = hero_is_on(d);
    sfVector2f position = sfSprite_getPosition(obj->sprite);
    if (!is_on || is_on->position.y >
        (position.y + obj->rect.height / 2) || is_on->position.y + 128 < position.y )
        sfSprite_move(obj->sprite, down);
}

void create_hero(data *d)
{
    sfIntRect rect = create_rect(512, 512, 0, 0);
    sfVector2f pos = {100, 0};
    sfVector2f vector = {0, 0};
    char filename[60] =
        "./Assets/BlueWizard/2BlueWizardWalk/Chara_BlueWalk00000.png";
    game_obj *hero = create_obj(filename, rect, pos, vector);
    set_scale(d, hero->sprite, 0.5);
    hero->animate = animate;
    hero->action = action;
    hero->grp = HERO;
    sfRenderWindow_drawSprite(d->window, hero->sprite, NULL);
    put_in_list(&d->objs, hero);
}