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

void jump_2(data *d, int mvt, game_obj *obj)
{
    sfIntRect rect = create_rect(512 * 16, 512, 0, 0);
    sfTexture *new = sfTexture_createFromFile(
        "./Assets/BlueWizard/2BlueWizardJump/DashEffect/spritesheet.png",
        &rect);
    sfSprite_setTexture(obj->sprite, new, sfTrue);
    obj->rect.left = 512 * 15;
    obj->animated_frame = 15;
    sfVector2f jump = {0, mvt};
    sound *s =
        create_sound("Assets/BlueWizard/2BlueWizardJump/Jump.wav", JUMP,
            100);
    put_in_list(&d->sounds, s);
    sfMusic_play(s->music);
    sfSprite_move(obj->sprite, jump);
    obj->up = 0;
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
        jump_2(d, mvt, obj);
    }
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
        if (event.key.code == sfKeyUp)
            jump(d, -128 * 2);
        if (event.key.code == sfKeyDown)
            jump(d, 128 * 2);
    }
}