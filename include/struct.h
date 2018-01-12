/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Struct file
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "main.h"

typedef struct obj_s {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	sfIntRect rect;
	int kill;
} obj_t;

typedef struct bg_s {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	sfIntRect rect;
} bg_t;

typedef struct menu_s {
	sfFont *font;
	sfText *text;
	sfVector2f pos;
} menu_t;

typedef struct sys_s {
	sfRenderWindow* win;
	sfEvent event;
	sfClock *clock;
	sfTime time;
	sfMusic *music_game;
	sfMusic *music_menu;
	sfMusic *music_menu_back;
	int status;
	int reset_map;
	int count_obj;
	int key;
	int game_status;
	int jump;
	int select;
	int have_player;
	int infinite_mod;
	long int_score;
	char **map;
	char *score;
	float seconds;
	obj_t *obj[10000];
	menu_t *menu[10000];
	bg_t *bg[8];
} sys_t;

#endif
