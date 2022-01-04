/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** move manager
*/

#include "include/list.h"
#include "include/runner.h"
#include <stdio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

void move_manager(data *d)
{
    game_obj *obj;
    node *tmp = d->objs;
    while (tmp != NULL) {
        obj = (game_obj *) tmp->data;
        if (obj->action != NULL)
            obj->action(obj, d);
        tmp = tmp->next;
    }
}