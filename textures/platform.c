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

void create_platform_texture(data *d)
{
    texture *t = malloc(sizeof(texture));
    t->animate = NULL;
    t->filename = "./Assets/Mossy Tileset/Mossy - FloatingPlatforms.png";
    t->name = "platform";
    t->rect = create_rect(2048, 2048, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}