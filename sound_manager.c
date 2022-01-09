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

void destroy_music(screen *hub)
{
    data *d;
    node *tmp = hub->datas;
    node *tmp_d;
    sound *t;
    while (tmp != NULL) {
        d = (data *)tmp->data;
        if (d != NULL)
            tmp_d = d->sounds;
        while (tmp_d != NULL) {
            t = (sound *)tmp_d->data;
            sfMusic_destroy(t->music);
            tmp_d = tmp_d->next;
        }
        tmp = tmp->next;
    }
}