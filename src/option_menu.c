/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void move_select_option_menu(sys_t *sys)
{
	if (sys->select > 3)
		sys->select = 1;
	if (sys->select < 1)
		sys->select = 3;
}

void select_option_menu(sys_t *sys)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		sys->select --;
		sfMusic_play(sys->music_menu);
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		sys->select ++;
		sfMusic_play(sys->music_menu);
	}
}

void choose_color_player_option_menu(sys_t *sys)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 1) {
		sys->obj[0] = add_sprite(sys,
			"assets/img/chracters/player_red.png",
			(sfVector2f){100, 764}, (sfIntRect){0, 0, 118, 100}, 0);
		sys->select = 1;
		sys->status = 0;
		sys->have_player = 1;
		sfMusic_play(sys->music_menu_back);
	}
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 2) {
		sys->obj[0] = add_sprite(sys,
			"assets/img/chracters/player_blue.png",
			(sfVector2f){100, 764}, (sfIntRect){0, 0, 118, 100}, 0);
		sys->select = 1;
		sys->status = 0;
		sys->have_player = 1;
		sfMusic_play(sys->music_menu_back);
	}
	back_option(sys);
}

void display_text_option_menu(sys_t *sys)
{
	int i = 0;

	for (i = 6; i != 9; i++) {
		sfText_setColor(sys->menu[i]->text, sfWhite);
		sfText_setCharacterSize(sys->menu[i]->text, 60);
	}
	if (sys->select + 5 == 6) {
		sfText_setColor(sys->menu[sys->select + 5]->text, sfRed);
		sfText_setCharacterSize(sys->menu[sys->select + 5]->text, 80);
	}
	else if (sys->select + 5 == 7) {
		sfText_setColor(sys->menu[sys->select + 5]->text, sfBlue);
		sfText_setCharacterSize(sys->menu[sys->select + 5]->text, 80);
	} else {
		sfText_setColor(sys->menu[sys->select + 5]->text, sfGreen);
		sfText_setCharacterSize(sys->menu[sys->select + 5]->text, 80);
	}
}

void render_option_menu(sys_t *sys)
{
	int i = 1;

	sfRenderWindow_drawSprite(sys->win, sys->bg[0]->sprite, NULL);
	sfRenderWindow_drawSprite(sys->win, sys->bg[2]->sprite, NULL);
	sfRenderWindow_drawSprite(sys->win, sys->bg[3]->sprite, NULL);
	for (i = 6; i != 10; i++)
		sfRenderWindow_drawText(sys->win, sys->menu[i]->text, NULL);
	sfRenderWindow_display(sys->win);
}
