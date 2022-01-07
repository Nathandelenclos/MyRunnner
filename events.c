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

void jump(data *d, int mvt)
{
    game_obj *obj;
    node *tmp = d->objs;
    while (tmp != NULL && obj->grp != HERO) {
        obj = (game_obj *) tmp->data;
        tmp = tmp->next;
    }
    if (obj->up) {
        obj->animated_frame = 15;
        free(obj->texture_file);
        obj->texture_file =
            my_strdup(
                "./Assets/BlueWizard/2BlueWizardJump/DashEffect/BlueWizardDash_00000.png");
        sfTexture
            *new = sfTexture_createFromFile(obj->texture_file, &obj->rect);
        sfSprite_setTexture(obj->sprite, new, sfTrue);
        sfVector2f jump = {0, mvt};
        sfSprite_move(obj->sprite, jump);
        obj->up = 0;
    }
}

void event_manager(data *d, sfEvent event)
{
    switch (event.type){
    case sfEvtClosed:
        event_closed(d);
        break;
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyEscape)
            event_closed(d);
        if (event.key.code == sfKeyUp)
            jump(d, -128 * 2);
        if (event.key.code == sfKeyDown)
            jump(d, 128 * 2);
    }
}