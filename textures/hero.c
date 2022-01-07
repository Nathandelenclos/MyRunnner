/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Texture
*/

#include "../include/list.h"
#include "../include/runner.h"
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

void animate_texture_hero(game_obj *obj)
{
    if (obj->rect.left == 0) {
        obj->animated_frame = 20;
        sfSprite_setTexture(obj->sprite, obj->texture->texture, sfTrue);
        obj->rect.left = 512 * 19;
    } else {
        obj->rect.left -= 512;
    }
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void create_hero_texture(data *d)
{
    texture *t = malloc(sizeof(texture));
    t->animate = animate_texture_hero;
    t->filename = "./Assets/BlueWizard/2BlueWizardWalk/spritesheet.png";
    t->name = "hero";
    t->rect = create_rect(10240, 512, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}