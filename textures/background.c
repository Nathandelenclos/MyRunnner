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

void create_background_textures(data *d)
{
    char *name = my_strdup("DarkForest_0");
    char *filename = my_strdup("./Assets/DarkForest/DarkForest_0.png");
    for (int i = 0; i < 4; ++i) {
        name[my_strlen(name) - 1] += 1;
        filename[my_strlen(filename) - 5] += 1;
        texture *t = malloc(sizeof(texture));
        t->animate = NULL;
        t->filename = my_strdup(filename);
        t->name = my_strdup(name);
        t->rect = create_rect(320, 180, 0, 0);
        t->texture = sfTexture_createFromFile(t->filename, &t->rect);
        put_in_list(&d->textures, t);
    }
    free(name);
    free(filename);
}