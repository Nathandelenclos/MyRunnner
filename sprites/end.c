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
#include <stdio.h>

game_obj *get_hero(data *d)
{
    game_obj *obj = NULL;
    node *tmp = d->objs;
    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (obj->grp == HERO)
            return obj;
        tmp = tmp->next;
    }
    return NULL;
}

void end_action(game_obj *obj, data *d)
{
    sfSprite_move(obj->sprite, obj->vector);
    game_obj *hero = get_hero(d);
    if (hero == NULL)
        return;
    node *victory = hero_is_on(d, VICTORY);
    if (victory) {
        sfRenderWindow_close(d->window);
        my_printf("Vous avez Gagner ! avec un score de %i", (int) (d->scrolling / 128));
    }
}

void create_end(data *d, int width, int height)
{
    sfIntRect rect = create_rect(128, 128, 0, 0);
    sfVector2f vector = {-6, 0};
    sfVector2f pos = {128 * (width), 128 * (height)};
    sfVector2f v[2] = {pos, vector};
    game_obj *obj = create_obj(d, NULL,rect, v);
    obj->grp = VICTORY;
    obj->action = end_action;
    put_in_list(&d->objs, obj);
}