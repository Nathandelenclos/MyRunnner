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

void start(screen *hub, sfRenderWindow *window)
{
    data *t = (data *) hub->datas->data;
    node *tmp = NULL;
    sfEvent event;
    tmp = hub->datas;
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (tmp != NULL && t->state != hub->state) {
            t = (data *) tmp->data;
            tmp = tmp->next;
        }
        t->screen(t, event);
        tmp = hub->datas;
    }
    sfRenderWindow_destroy(window);
    destroy_music(hub);
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    char *t = "./my_runner: bad arguments: 0 given but 1 is required retry with -h";
    if (argc < 2) {
        my_printf(t);
        return 84;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        return print_h();
    screen *hub = malloc(sizeof(screen));
    hub->state = START;
    sfVideoMode mode = {1080 * 1.3, 720 * 1.3, 32};
    sfRenderWindow
        *window = sfRenderWindow_create(mode, "MyRunner", sfDefaultStyle,
        NULL);
    screen_manager(hub, argv[1], window, mode);
    start(hub, window);
    return 0;
}
