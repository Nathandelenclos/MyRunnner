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
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

sound *create_sound(char *filename, enum sound_grp grp, float volume)
{
    sound *s = malloc(sizeof(sound));
    s->music = sfMusic_createFromFile(filename);
    sfMusic_setVolume(s->music, volume);
    s->grp = grp;
    return s;
}

void sound_manager(data *d)
{
    sound *music = create_sound("resources/breathe.wav", MUSIC, 25);
    put_in_list(&d->sounds, music);
    put_in_list(&d->sounds,
        create_sound("Assets/BlueWizard/2BlueWizardJump/Jump.wav", JUMP, 25));
    sfMusic_play(music->music);
}

void destroy_music(data *d)
{
    sound *t;
    node *tmp = d->sounds;
    while (tmp != NULL) {
        t = (sound *)tmp->data;
        sfMusic_destroy(t->music);
        tmp = tmp->next;
    }
}