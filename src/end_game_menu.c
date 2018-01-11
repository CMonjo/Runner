/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Game detection file
*/

#include "main.h"

void end_menu(sys_t *sys)
{
	sys->menu[10] = set_text("assets/font/bold.ttf", (sfVector2f){450, 900}, sys->score, 50);
	sfRenderWindow_drawSprite(sys->win, sys->bg[0]->sprite, NULL);
	sfRenderWindow_drawText(sys->win, sys->menu[10]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->menu[11]->text, NULL);
	if (sys->game_status == 0)
		sfRenderWindow_drawText(sys->win, sys->menu[12]->text, NULL);
	if (sys->game_status == 1)
		sfRenderWindow_drawText(sys->win, sys->menu[13]->text, NULL);
	sfText_setColor(sys->menu[14]->text, sfGreen);
	sfRenderWindow_drawText(sys->win, sys->menu[14]->text, NULL);
	analyse_events(sys);
	if (sfKeyboard_isKeyPressed(sfKeyReturn))
		sfRenderWindow_close(sys->win);
	sfRenderWindow_display(sys->win);
}
