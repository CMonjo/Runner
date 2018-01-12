/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void analyse_events(sys_t *sys)
{
	while (sfRenderWindow_pollEvent(sys->win, &(sys->event))) {
		if (sys->event.type == sfEvtClosed) {
			sfRenderWindow_close(sys->win);
		}
	}
}

void init_window(sys_t *sys)
{
	sfVideoMode mode = {1920, 1080, 32};
	sys->win = sfRenderWindow_create(mode, "MyRunner", sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(sys->win, 60);
	sys->clock = sfClock_create();
	sys->music_game = sfMusic_createFromFile("assets/music/game.wav");
	sys->music_menu = sfMusic_createFromFile("assets/music/menu_select.wav");
	sys->music_menu_back = sfMusic_createFromFile("assets/music/menu_back.wav");
	sys->status = 0;
	sys->select = 1;
	sys->have_player = 0;
	if (sys->key == 0)
		sys->infinite_mod = 0;
	sys->jump = 0;
	sys->int_score = 0;
	init_text_menu(sys);
	init_objects(sys);
	compare_map(sys);
	sfRenderWindow_setMouseCursorVisible(sys->win, sfFalse);
}

void which_mod(sys_t *sys)
{
	if (sys->infinite_mod == 0) {
		scrolling_map(sys);
		check_victory(sys);
	} else
		scrolling_infinite_map(sys);
}

void which_status(sys_t *sys)
{
	if (sys->status == 0)
		main_menu(sys);
	else if (sys->status == 1)
		end_menu(sys);
	else if (sys->status == 2)
		option_menu(sys);
	else {
		sfRenderWindow_clear(sys->win, sfBlack);
		analyse_events(sys);
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

void my_window(sys_t *sys)
{
	init_window(sys);
	sfMusic_play(sys->music_game);
	sfMusic_setLoop(sys->music_game, sfTrue);
	while (sfRenderWindow_isOpen(sys->win)) {
		sfRenderWindow_clear(sys->win, sfBlack);
		sys->time = sfClock_getElapsedTime(sys->clock);
		sys->seconds = sys->time.microseconds / 1000000.0;
		which_status(sys);
	}
	destroy_objects(sys);
}
