/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** text
*/

#include "../include/list.h"
#include "../include/runner.h"
#include "../include/my.h"
#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>

void animate_score(text *t, data *d)
{
    char points[245];
    char points_s[255];
    points_s[0] = '\0';
    my_int_to_str((int) (d->scrolling / 128), points, 10);
    my_strcat(points_s, "Distance: ");
    my_strcat(points_s, points);
    modify_string(d, t->string, my_strdup(points_s));
}

void display_score(data *d)
{
    char points[245];
    char points_s[255];
    points_s[0] = '\0';
    my_int_to_str((int) (d->scrolling / 128), points, 10);
    my_strcat(points_s, "Distance: ");
    my_strcat(points_s, points);
    sfVector2f pos = {0, 0};
    text *t = create_text(my_strdup(points_s), sfBlack, pos);
    t->animate = animate_score;
    put_in_list(&d->texts, t);
}