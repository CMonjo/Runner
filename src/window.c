/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void analyse_events(sys_t *sys)
{
	while (sfRenderWindow_pollEvent(sys->win,
		&(sys->event))) {
		if (sys->event.type == sfEvtClosed) {
			sfRenderWindow_close(sys->win);
		}
	}
}

void which_status_game_loop(sys_t *sys)
{
	if (sys->status == 2)
		option_menu(sys);
	else {
		render_objects(sys);
		check_jump(sys);
		check_collision(sys);
		if (sys->seconds > 0.02) {
			move_player(sys);
			display_score(sys);
			sfClock_restart(sys->clock);
		}
		draw_background(sys);
		which_mod(sys);
	}
}

void which_status(sys_t *sys)
{
	if (sys->status == 0)
		main_menu(sys);
	else if (sys->status == 1)
		end_menu(sys);
	else
		which_status_game_loop(sys);
}

void my_window(sys_t *sys)
{
	init_window(sys);
	sfMusic_play(sys->music_game);
	sfMusic_setLoop(sys->music_game, sfTrue);
	while (sfRenderWindow_isOpen(sys->win)) {
		sfRenderWindow_clear(sys->win, sfBlack);
		analyse_events(sys);
		sys->time = sfClock_getElapsedTime(sys->clock);
		sys->seconds = sys->time.microseconds / 1000000.0;
		which_status(sys);
	}
	destroy_objects(sys);
}
