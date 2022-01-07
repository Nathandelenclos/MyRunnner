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

text *create_text(char *string, sfColor color, sfVector2f po)
{
    text *t = malloc(sizeof(text));
    t->text = sfText_create();
    t->font = sfFont_createFromFile("./resources/font.ttf");
    sfText_setFont(t->text, t->font);
    t->string = my_strdup(string);
    sfText_setString(t->text, t->string);
    t->color = color;
    sfText_setFillColor(t->text, t->color);
    t->position = po;
    sfText_setPosition(t->text, t->position);
    return t;
}

void create_texts(data *d)
{
    display_score(d);
}

void modify_string(data *d, char *before, char *after)
{
    text *t;
    node *tmp = d->texts;
    while (tmp != NULL) {
        t = (text *)tmp->data;
        if (t->string == before) {
            free(t->string);
            t->string = my_strdup(after);
            sfText_setString(t->text, t->string);
        }
        tmp = tmp->next;
    }
}

void text_manager(data *d)
{
    text *t;
    node *tmp = d->texts;
    while (tmp != NULL) {
        t = (text *)tmp->data;
        sfRenderWindow_drawText(d->window, t->text, NULL);
        tmp = tmp->next;
    }
}