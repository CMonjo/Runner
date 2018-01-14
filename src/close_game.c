/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void destroy_objects(sys_t *sys)
{
	int i = 0;

	for (i = 0; sys->obj[i] != NULL; i++) {
		sfSprite_destroy(sys->obj[i]->sprite);
		sfTexture_destroy(sys->obj[i]->texture);
	}
	for (i = 0; sys->bg[i] != NULL; i++) {
		sfSprite_destroy(sys->bg[i]->sprite);
		sfTexture_destroy(sys->bg[i]->texture);
	}
	for (i = 0; sys->menu[i] != NULL; i++) {
		sfText_destroy(sys->menu[i]->text);
		sfFont_destroy(sys->menu[i]->font);
	}
	sfClock_destroy(sys->clock);
	sfMusic_destroy(sys->music_game);
	sfMusic_destroy(sys->music_menu);
	sfMusic_destroy(sys->music_menu_back);
	sfRenderWindow_destroy(sys->win);
}

void free_options(sys_t *sys)
{
	int i = 0;

	for (i = 0; i != 10; i++)
		free(sys->map[i]);
	for (i = 0; sys->obj[i] != NULL; i++)
		free(sys->obj[i]);
	for (i = 0; sys->menu[i] != NULL; i++)
		free(sys->menu[i]);
	free(sys->map);
	free(sys->score);
	free(sys);
}
