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

void animate_texture_green_slime(game_obj *obj)
{
    if (obj->rect.left == 0)
        obj->rect.left = 376 * 29;
    else
        obj->rect.left -= 376;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void create_green_slime_texture(data *d)
{
    texture *t = malloc(sizeof(texture));
    t->animate = animate_texture_green_slime;
    t->filename = "./Assets/SlimeGreen/spritesheet.png";
    t->name = "green slime";
    t->rect = create_rect(376 * 30, 256, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}