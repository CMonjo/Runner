/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <stdarg.h>
	#include <math.h>
	#include <SFML/Graphics.h>
	#include <SFML/Window.h>
	#include <SFML/System/Vector2.h>
	#include <SFML/Audio.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <dirent.h>
	#include <time.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include <fcntl.h>
	#include "struct.h"
	int my_putstr(char const *str);
	void check_victory(sys_t *sys);
	int my_put_nbr(int nb);
	void my_putchar(char c);
	int my_strlen(char const *str);
	obj_t *add_sprite(sys_t *sys, const char *path_sprite, sfVector2f pos, sfIntRect rect, int kill);
	bg_t *add_sprite_bg(const char *path_sprite, sfVector2f pos, sfIntRect rect);
	menu_t *set_text(char *font, sfVector2f pos, char *text, int size);
	int main(int ac, char **av);
	int open_map(sys_t *sys, char const *filepath);
	void free_options(sys_t *sys);
	void destroy_objects(sys_t *sys);
	void analyse_events(sys_t *sys);
	void init_window(sys_t *sys);
	void my_window(sys_t *sys);
	void init_ground(sys_t *sys, int obj, int pos_y, int pos_x);
	void init_dirt(sys_t *sys, int obj, int pos_y, int pos_x);
	void init_water(sys_t *sys, int obj, int pos_y, int pos_x);
	void create_variable(sys_t *sys);
	int init_runner(char **av);
	int print_h(char const *filepath);
	void compare_map(sys_t *sys);
	void init_objects(sys_t *sys);
	void move_player(sys_t *sys);
	void render_objects(sys_t *sys);
	void scrolling_map(sys_t *sys);
	void scrolling_infinite_map(sys_t *sys);
	void draw_background(sys_t *sys);
	void init_text_menu(sys_t *sys);
	void render_option_menu(sys_t *sys);
	void select_option_menu(sys_t *sys);
	void choose_color_player_option_menu(sys_t *sys);
	void display_text_option_menu(sys_t *sys);
	void option_menu(sys_t *sys);
	void select_main_menu(sys_t *sys);
	void choose_option_main_menu(sys_t *sys);
	void which_item(sys_t *sys);
	void back_option(sys_t *sys);
	void choose_game_main_menu(sys_t *sys);
	void choose_player_main_menu(sys_t *sys);
	void render_main_menu(sys_t *sys);
	void display_text_main_menu(sys_t *sys);
	void init_tree(sys_t *sys, int obj, int pos_y, int pos_x);
	void init_obstacles(sys_t *sys, int obj, int pos_y, int pos_x);
	void init_mace(sys_t *sys, int obj, int pos_y, int pos_x);
	void init_saw(sys_t *sys, int obj, int pos_y, int pos_x);
	void init_square_tree(sys_t *sys, int obj, int pos_y, int pos_x);
	void main_menu(sys_t *sys);
	void which_mod(sys_t *sys);
	void which_status(sys_t *sys);
	void init_score(sys_t *sys, long nbr);
	void check_collision(sys_t *sys);
	void check_jump(sys_t *sys);
	void display_score(sys_t *sys);
	void jump_player(sys_t *sys);
	void render_end(sys_t *sys);
	void end_menu(sys_t *sys);
	void which_end_option(sys_t *sys);
	void display_end_menu(sys_t *sys);
	void restart_game_loop(sys_t *sys);
	void move_select_menu(sys_t *sys, int max, int min);
#endif
