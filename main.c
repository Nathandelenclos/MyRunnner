/*
** EPITECH PROJECT, 2021
** MyRunner
** File description:
** main
*/

#include "include/my.h"
#include "include/runner.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>

data *init_data(char *filename)
{
    sfVideoMode mode = {1080 * 1.3, 720 * 1.3, 32};
    data *d = malloc(sizeof(data));
    d->objs = NULL;
    d->texts = NULL;
    d->sounds = NULL;
    d->textures = NULL;
    d->mode = mode;
    d->state = START;
    d->window = sfRenderWindow_create(mode, "MyRunner", sfDefaultStyle, NULL);
    d->font = sfFont_createFromFile("resources/font.ttf");
    d->scrolling = 250;
    create_textures(d);
    create_hero(d);
    create_texts(d);
    map_manager(filename, d);
    sound_manager(d);
    create_background(d);
    return d;
}

int print_h(void)
{
    my_printf("Finite runner created with CSFML\n\n");
    my_printf("USAGE\n");
    my_printf("\t-./my_runner map.txt\n");
    my_printf("OPTIONS`\n");
    my_printf("\t-h\tprint the usage and quit.\n");
    my_printf("USER INTERACTIONS:\n");
    my_printf("\tUP\tjump / dash up.\n");
    my_printf("\tDOWN\tdash down.\n");
    return 0;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    if (argc < 2)
        return my_error("./my_runner: bad arguments: 0 given but 1 is required retry with -h");
    if (argc < 2 || (argv[1][0] == '-' && argv[1][1] == 'h'))
        return print_h();
    data *data = init_data(argv[1]);
    sfEvent event;
    void (*func[3])(struct data_s *, sfEvent) = {
        start_screen, play_screen, NULL
    };
    sfRenderWindow_setFramerateLimit(data->window, 60);
    while (sfRenderWindow_isOpen(data->window))
        (*func[data->state])(data, event);
    sfRenderWindow_destroy(data->window);
    destroy_music(data);
    return 0;
}
