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

enum group {
    HERO,
    BACKGROUND,
    MAP,
    ENEMY,
    VICTORY,
    WIDGET
};

enum state {
    START = 0,
    END = 1,
    PLAY = 2,
    RESUME = 3,
    DEATH = 4,
    WIN = 5,
};

enum sound_grp {
    JUMP,
    MUSIC
};

struct game_obj_s;
struct data_s;

typedef struct screen_s {
    enum state state;
    node *datas;
} screen;

typedef struct data_s {
    node *objs;
    node *texts;
    node *sounds;
    node *textures;
    sfRenderWindow *window;
    screen *hub;
    enum state state;
    sfVideoMode mode;
    sfFont *font;
    int scrolling;
    char *filemap;
    void (*screen)(struct data_s *data, sfEvent event);
} data;

typedef struct texture_s {
    sfTexture *texture;
    sfIntRect rect;
    char *filename;
    void (*animate)(struct game_obj_s *);
    char *name;
} texture;

typedef struct game_obj_s {
    enum group grp;
    int animated_frame;
    sfSprite *sprite;
    texture *texture;
    sfIntRect rect;
    sfVector2f position;
    char *name;
    void (*action)(struct game_obj_s *, data *);
    void (*animate)(struct game_obj_s *);
    int up;
    sfClock *clock;
    sfVector2f vector;
    sfTime time;
    float seconds;
} game_obj;

typedef struct sound_d {
    sfMusic *music;
    enum sound_grp grp;
} sound;

typedef struct text_s {
    sfFont *font;
    char *string;
    sfText *text;
    sfVector2f position;
    sfColor color;
    void (*animate)(struct text_s *, data *d);
} text;

void event_manager(data *d, sfEvent event);
void sprites_manager(data *d);
void create_background(data *d);
void create_hero(data *d);
game_obj *create_obj(
    data *d, char *texture_name, sfIntRect rect, sfVector2f *vector
);
void set_scale(data *d, sfSprite *sprite, float multiplier);
void time_manager(data *d);
void create_safe_platform(data *d, int width, int height);
void create_enemy_platform(data *d, int width, int height);
void create_enemy_peak(data *d, int width, int height);
void map_manager(char *map_name, data *d);
sfIntRect create_rect(int width, int height, int left, int top);
void move_manager(data *d);
void create_green_slime(data *d, int width, int height);
void create_safe_platform_right(data *d, int width, int height);
void create_safe_platform_left(data *d, int width, int height);
text *create_text(
    char *string, sfColor color, sfVector2f po, sfVector2f scale
    );
void modify_string(data *d, char *before, char *after);
void text_manager(data *d);
void display_score(data *d);
void create_texts(data *d);
texture *get_texture(data *d, char *name);
void create_hero_texture(data *d);
void create_background_textures(data *d);
void create_textures(data *d);
void create_green_slime_texture(data *d);
void create_platform_texture(data *d);
void create_end(data *d, int width, int height);
node *hero_is_on(data *d, enum group grp);
game_obj *get_hero(data *d);
void sound_manager(data *d);
void destroy_music(screen *hub);
sound *create_sound(char *filename, enum sound_grp grp, float volume);
void screen_manager(
    screen *s, char *filename, sfRenderWindow *window, sfVideoMode mode
);
void *data_play(
    screen *screen1, char *filename, sfRenderWindow *window, sfVideoMode mode
);
void create_widget_texture(data *d);
void create_btn(data *d, float x, float y, char *name);
void *data_start(
    screen *screen1, char *filename, sfRenderWindow *window, sfVideoMode mode
);
void *data_death(
    screen *screen1, char *filename, sfRenderWindow *window, sfVideoMode mode
);
game_obj *is_on_btn(data *d, sfMouseButtonEvent event);
void *data_win(
    screen *screen1, char *filename, sfRenderWindow *window, sfVideoMode mode
);
void *data_pause(
    screen *screen1, char *filename, sfRenderWindow *window, sfVideoMode mode
);
#endif