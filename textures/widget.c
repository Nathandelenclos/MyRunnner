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

void create_widget_texture(data *d)
{
    texture *t = malloc(sizeof(texture));
    t->animate = NULL;
    t->filename = "./Assets/widget.png";
    t->name = "widget";
    t->rect = create_rect(271, 129, 0, 0);
    t->texture = sfTexture_createFromFile(t->filename, &t->rect);
    put_in_list(&d->textures, t);
}