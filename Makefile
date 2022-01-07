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
			move_manager.c	\
			screens.c	\
			sprites/background.c	\
			sprites/safe_platform.c	\
			sprites/safe_platform_border_right.c	\
			sprites/safe_platform_border_left.c	\
			sprites/enemy_platform.c	\
			sprites/enemy_peak.c	\
			sprites/green_slime.c	\
			sprites/hero.c	\
			texts/score.c	\

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
