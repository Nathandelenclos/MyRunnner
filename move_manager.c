/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** move manager
*/

#include "include/list.h"
#include "include/runner.h"
#include "include/my.h"
#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

int is_integer(float f)
{
    if (f == (int) f)
        return 0;
    return 1;
}

void move_manager(data *d)
{
    game_obj *obj;
    text *t;
    node *tmp = d->objs;
    d->scrolling += 6;

    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (obj->action != NULL)
            obj->action(obj, d);
        tmp = tmp->next;
    }
    tmp = d->texts;
    while (tmp != NULL) {
        t = (text *) tmp->data;
        if (t->animate != NULL)
            t->animate(t, d);
        tmp = tmp->next;
    }
}