/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Game detection file
*/

#include "main.h"

void jump_player(sys_t *sys)
{
	static int key = 0;

	if (key == 0) {
		sys->obj[0]->pos.y = sys->obj[0]->pos.y - 14;
		if (sys->obj[0]->pos.y <= 580)
			key = 1;
		sys->jump = 1;
	}
	else if (key == 1) {
		sys->obj[0]->pos.y += 14;
		if (sys->obj[0]->pos.y >= 764) {
			key = 0;
			sys->jump = 0;
		}
	}
	sfSprite_setPosition(sys->obj[0]->sprite, sys->obj[0]->pos);
}

void check_collision(sys_t *sys)
{
	int i = 0;
	unsigned int player_x = sys->obj[0]->pos.x;
	unsigned int player_y = sys->obj[0]->pos.y;
	unsigned int obj_x = 0;
	unsigned int obj_y = 0;

	for (i = 1; sys->obj[i] != NULL; i++) {
		obj_x = sys->obj[i]->pos.x;
		obj_y = sys->obj[i]->pos.y;
		if (((player_x + 75 >= obj_x && player_x <= obj_x) && (player_y + 100 >= obj_y && player_y < obj_y) && sys->obj[i]->kill == 1)) {
				sys->game_status = 1;
				sys->status = 1;
		}
	}
}

void check_victory(sys_t *sys)
{
	if (sys->obj[0]->pos.x >= sys->obj[sys->count_obj - 1]->pos.x) {
		sys->game_status = 0;
		sys->status = 1;
	}
}
