/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void back_option(sys_t *sys)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 3) {
		sys->select = 1;
		sys->status = 0;
		sfMusic_play(sys->music_menu_back);
	}
}

void main_menu(sys_t *sys)
{
	render_main(sys);
	if (sys->seconds > 0.1) {
		which_select_main(sys);
		start_game(sys);
		choose_option(sys);
		display_text_main_menu(sys);
	}
}

void option_menu(sys_t *sys)
{
	render_option(sys);
	if (sys->seconds > 0.1) {
		which_select_option(sys);
		select_color_player(sys);
		display_text_option_menu(sys);
		sfClock_restart(sys->clock);
	}
}
