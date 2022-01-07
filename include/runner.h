/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** header file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "list.h"

#ifndef RUNNER_H
    #define RUNNER_H

enum GRP {
    HERO,
    BACKGROUND,
    MAP,
    ENEMY
};

enum state {
    START = 0,
    END = 1,
    PLAY = 2,
    RESUME = 3
};

typedef struct data_s {
    node *objs;
    node *texts;
    sfRenderWindow *window;
    int state;
    sfVideoMode mode;
    sfFont *font;
    sfMusic *music;
    int scrolling;
} data;

typedef struct game_obj_s {
    enum GRP grp;
    int animated_frame;
    sfSprite *sprite;
    sfTexture *texture;
    char *texture_file;
    sfIntRect rect;
    sfVector2f position;
    void (*action)(struct game_obj_s *, data *d);
    void (*animate)(struct game_obj_s *);
    int up;
    sfClock *clock;
    sfVector2f vector;
    sfTime time;
    float seconds;
} game_obj;

typedef struct text_s {
    sfFont *font;
    char *string;
    sfText *text;
    sfVector2f position;
    sfColor color;
} text;

void event_manager(data *d, sfEvent event);
void sprites_manager(data *d);
void create_background(data *d);
void create_hero(data *d);
game_obj *create_obj(
    char *filename, sfIntRect rect, sfVector2f position, sfVector2f vector
);
void set_scale(data *d, sfSprite *sprite, float multiplier);
void time_manager(data *d);
void create_safe_platform(data *d, int width, int height);
void create_enemy_platform(data *d, int width, int height);
void create_enemy_peak(data *d, int width, int height);
void map_manager(char *map_name, data *d);
sfIntRect create_rect(int width, int height, int left, int top);
void move_manager(data *d);
void play_screen(struct data_s *data, sfEvent event);
void start_screen(struct data_s *data, sfEvent event);
void create_green_slime(data *d, int width, int height);
void create_safe_platform_right(data *d, int width, int height);
void create_safe_platform_left(data *d, int width, int height);

#endif