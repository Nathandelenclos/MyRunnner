/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Manager
*/

#include "include/list.h"
#include "include/runner.h"
#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

texture *get_texture(data *d, char *name)
{
    texture *t;
    node *tmp = d->textures;
    if (name == NULL)
        return NULL;
    while (tmp != NULL) {
        t = (texture *)tmp->data;
        if (my_strcmp(t->name, name))
            return t;
        tmp = tmp->next;
    }
    return NULL;
}

void create_textures(data *d)
{
    create_background_textures(d);
    create_platform_texture(d);
    create_hero_texture(d);
    create_green_slime_texture(d);
}