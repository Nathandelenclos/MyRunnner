/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** events
*/

#include "include/my.h"
#include "include/list.h"
#include "include/runner.h"
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

void event_closed(data *d)
{
    sfRenderWindow_close(d->window);
}

void jump(data *d)
{
    game_obj *obj;
    node *tmp = d->objs;
    while (tmp != NULL && obj->grp != HERO) {
        obj = (game_obj *) tmp->data;
        tmp = tmp->next;
    }
    if (obj->rect.top == 35 + 80 + 80)
        return;
    obj->rect.top += 80;
    obj->rect.left = 430;
    sfVector2f jump = {0, -160};
    sfSprite_move(obj->sprite, jump);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void event_manager(data *d, sfEvent event)
{
    switch (event.type) {
    case sfEvtClosed:
        event_closed(d);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            event_closed(d);
        if (event.key.code == sfKeySpace)
            jump(d);
    }
}