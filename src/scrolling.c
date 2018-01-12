/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Background file
*/

#include "main.h"

void scrolling_map(sys_t *sys)
{
	int i = 1;

	sys->reset_map += 14;
	for (i = 1; sys->obj[i] != NULL; i++) {
		sys->obj[i]->pos.x = sys->obj[i]->pos.x - 14;
		sfSprite_setPosition(sys->obj[i]->sprite, sys->obj[i]->pos);
	}
}

void scrolling_infinite_map(sys_t *sys)
{
	int i = 1;

	sys->reset_map += 14;
	for (i = 1; sys->obj[i] != NULL; i++) {
		if (sys->obj[i]->pos.x <= -200) {
			sys->obj[i]->pos.x = sys->obj[i]->pos.x + 2200;
		}
		sys->obj[i]->pos.x = sys->obj[i]->pos.x - 14;
		sfSprite_setPosition(sys->obj[i]->sprite, sys->obj[i]->pos);
	}
}

void draw_background(sys_t *sys)
{
	int i = 4;
	sfVector2f pos_tmp = {0, 0};

	for (i = 4; i < 7; i++) {
		if (sys->bg[i]->pos.x == -1920)
			sys->bg[i]->pos.x = 0;
		pos_tmp.x = sys->bg[4]->pos.x - 1920;
		sfSprite_setPosition(sys->bg[i]->sprite, pos_tmp);
		sfRenderWindow_drawSprite(sys->win, sys->bg[i]->sprite, NULL);
	}
	sys->bg[4]->pos.x = sys->bg[4]->pos.x - 5;
	sys->bg[5]->pos.x = sys->bg[5]->pos.x - 4;
	sys->bg[6]->pos.x = sys->bg[6]->pos.x - 3;
	sfSprite_setPosition(sys->bg[4]->sprite, sys->bg[4]->pos);
	sfSprite_setPosition(sys->bg[5]->sprite, sys->bg[5]->pos);
	sfSprite_setPosition(sys->bg[6]->sprite, sys->bg[6]->pos);
}
