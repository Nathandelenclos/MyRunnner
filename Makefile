##
## EPITECH PROJECT, 2021
## Day12
## File description:
## makefile
##

MAIN	=	main.c	\

SRC	=		events.c	\
			sprites_manager.c	\
			time_manager.c	\
			map_manager.c	\
			text_manager.c	\
			sound_manager.c	\
			texture_manager.c	\
			screen_manager.c	\
			move_manager.c	\
			screens.c	\
			sprites/background.c	\
			sprites/end.c	\
			sprites/safe_platform.c	\
			sprites/safe_platform_border_right.c	\
			sprites/safe_platform_border_left.c	\
			sprites/green_slime.c	\
			sprites/btn.c	\
			sprites/hero.c	\
			texts/score.c	\
			textures/hero.c	\
			textures/widget.c	\
			textures/background.c	\
			textures/green_slime.c	\
			textures/platform.c	\
			screens/play.c	\
			screens/main_menu.c	\
			screens/win.c	\
			screens/pause.c	\
			screens/death_end.c	\

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o)

TEST_FILE	=		\

NAME	=	my_runner

LIB	=	-lcsfml-graphics	\
		-lcsfml-window	\
		-lcsfml-system	\
		-lcsfml-audio	\
		-llist	\
		-lmy

CFLAGS	=	-g

all:	buildlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C ./lib/my/ fclean
	make -C ./lib/linked_list/ fclean

re:	fclean all

exe:
	./$(NAME)

buildlib:
	make -C ./lib/my/
	make -C ./lib/linked_list/

tests_run:
	gcc -o unit_tests $(SRC) $(TEST_FILE) -L./lib $(LIB)
	./unit_tests
	rm unit_tests*

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L./lib $(LIB)
