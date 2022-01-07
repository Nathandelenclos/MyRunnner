/*
** EPITECH PROJECT, 2021
** MyHunter
** File description:
** sprite
*/

/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** Sprite
*/

#include "../include/list.h"
#include "../include/runner.h"
#include "../include/my.h"
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

void green_slime_action(game_obj *obj, data *d)
{
    sfSprite_move(obj->sprite, obj->vector);
}

char *new_filename_slime(char *string)
{
    char *filename = my_strdup(string);
    if (filename[my_strlen(filename) - 5] == '9') {
        filename[my_strlen(filename) - 5] = '0';
        if (filename[my_strlen(filename) - 6] == '0')
            filename[my_strlen(filename) - 6] = '1';
        else if (filename[my_strlen(filename) - 6] == '1')
            filename[my_strlen(filename) - 6] = '2';
        else
            filename[my_strlen(filename) - 6] = '0';
    } else {
        filename[my_strlen(filename) - 5] += 1;
    }
    return filename;
}

void green_slime_animate(game_obj *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->seconds = obj->time.microseconds / 1000000.0;
    if (obj->seconds >= 1 / 30) {
        char *filename = new_filename_slime(obj->texture_file);
        sfTexture *new = sfTexture_createFromFile(filename, &obj->rect);
        free(obj->texture_file);
        obj->texture_file = filename;
        sfSprite_setTexture(obj->sprite, new, sfTrue);
        sfVector2f scale = {1 / 2, 1 / 2};
        sfSprite_setScale(obj->sprite, scale);
        sfClock_restart(obj->clock);
    }
}

void create_green_slime(data *d, int width, int height)
{
    int size = 256;
    sfIntRect rect = create_rect(376, size, 0, 0);
    sfVector2f vector = {-6, 0};
    sfVector2f
        pos = {128 * (width), 128 * (height)};
    game_obj
        *obj =
        create_obj("./Assets/SlimeGreen/SlimeBasic_00000.png", rect,
            pos, vector);
    rect = create_rect(376, 256, 0, 0);
    sfSprite_setTextureRect(obj->sprite, rect);
    set_scale(d, obj->sprite, 0.5);
    obj->animate = green_slime_animate;
    obj->action = green_slime_action;
    obj->grp = MAP;
    sfRenderWindow_drawSprite(d->window, obj->sprite, NULL);
    put_in_list(&d->objs, obj);
}