/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Init map file
*/

#include "main.h"

void init_ground(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/hud/ground.png",
	(sfVector2f){pos_x * 96, pos_y * 108}, (sfIntRect){0, 0, 96, 108}, 0);
}

void init_dirt(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/hud/dirt.png",
	(sfVector2f){pos_x * 96, pos_y * 108}, (sfIntRect){0, 0, 96, 108}, 0);
}

void init_water(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/hud/water.png",
	(sfVector2f){pos_x * 96, pos_y * 108}, (sfIntRect){0, 0, 96, 108}, 0);
}

void init_tree(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/hud/tree.png",
	(sfVector2f){pos_x * 90, pos_y * 88}, (sfIntRect){0, 0, 220, 256}, 0);
}

void init_square_tree(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/hud/square_tree.png",
	(sfVector2f){pos_x * 96, pos_y * 91}, (sfIntRect){0, 0, 149, 239}, 0);
}

void init_obstacles(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/chracters/obstacles.png",
	(sfVector2f){pos_x * 96, pos_y * 120}, (sfIntRect){0, 0, 96, 32}, 1);
}

void init_mace(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/chracters/mace.png",
	(sfVector2f){pos_x * 96, pos_y * 108}, (sfIntRect){0, 0, 96, 108}, 1);
}

void init_saw(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/chracters/saw.png",
	(sfVector2f){pos_x * 96, pos_y * 118}, (sfIntRect){0, 0, 96, 108}, 1);
}


void compare_map(sys_t *sys)
{
	int pos_y = 0;
	int pos_x = 0;
	int obj = 0;

	while (pos_y != 10) {
		while (sys->map[pos_y][pos_x] != '\n') {
			if (sys->map[pos_y][pos_x] == '1') {
				obj++;
				init_ground(sys, obj, pos_y, pos_x);
			}
			if (sys->map[pos_y][pos_x] == '2') {
				obj++;
				init_dirt(sys, obj, pos_y, pos_x);
			}
			if (sys->map[pos_y][pos_x] == '3') {
				obj++;
				init_water(sys, obj, pos_y, pos_x);
			}
			if (sys->map[pos_y][pos_x] == 'T') {
				obj++;
				init_square_tree(sys, obj, pos_y, pos_x);
			}
			if (sys->map[pos_y][pos_x] == 'F') {
				obj++;
				init_tree(sys, obj, pos_y, pos_x);
			}
			if (sys->map[pos_y][pos_x] == 'O') {
				obj++;
				init_obstacles(sys, obj, pos_y, pos_x);
			}
			if (sys->map[pos_y][pos_x] == 'S') {
				obj++;
				init_saw(sys, obj, pos_y, pos_x);
			}
			if (sys->map[pos_y][pos_x] == 'M') {
				obj++;
				init_mace(sys, obj, pos_y, pos_x);
			}
			pos_x++;
		}
		pos_y++;
		pos_x = 0;
	}
}
