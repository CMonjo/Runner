##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile project
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -I include/ -lc_graph_prog

CFLAGT	=	-Wall -Wextra -W -I include/ -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

LIB	=	-L ./lib/ -lmy

SRC	=	src/main.c		\
		src/window.c		\
		src/engine.c		\
		src/scrolling.c		\
		src/check_map.c		\
		src/main_menu.c		\
		src/display_menu.c	\
		src/option_menu.c	\
		src/close_game.c	\
		src/score.c		\
		src/game_detection.c	\
		src/init_game.c		\
		src/add_enemies_sprite.c\
		src/add_decor_sprite.c	\
		src/end_game_menu.c	\
		src/restart_game.c	\
		src/objects_handling.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)
	rm -f $(OBJ)
	make clean -C ./lib/my/

run: $(OBJ)
	make -C ./lib/my/
	$(CC) $(OBJ) $(CFLAGT) $(LIB) -o $(NAME)
	rm -f $(OBJ)
	make clean -C ./lib/my/
clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re: fclean all
