/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Init map file
*/

#include "main.h"

// switch (str[i + 1]) {
// 	case '+':
// 		my_putchar('+', count);
// 		break;
// }
// if (sys->map[pos_y][pos_x] == '1') {
// 	obj++;
// 	init_ground(sys, obj, pos_y, pos_x);
// }
// if (sys->map[pos_y][pos_x] == '2') {
// 	obj++;
// 	init_dirt(sys, obj, pos_y, pos_x);
// }
// if (sys->map[pos_y][pos_x] == '3') {
// 	obj++;
// 	init_water(sys, obj, pos_y, pos_x);
// }
// if (sys->map[pos_y][pos_x] == 'T') {
// 	obj++;
// 	init_square_tree(sys, obj, pos_y, pos_x);
// }
// if (sys->map[pos_y][pos_x] == 'F') {
// 	obj++;
// 	init_tree(sys, obj, pos_y, pos_x);
// }
// if (sys->map[pos_y][pos_x] == 'O') {
// 	obj++;
// 	init_obstacles(sys, obj, pos_y, pos_x);
// }
// if (sys->map[pos_y][pos_x] == 'S') {
// 	obj++;
// 	init_saw(sys, obj, pos_y, pos_x);
// }
// if (sys->map[pos_y][pos_x] == 'M') {
// 	obj++;
// 	init_mace(sys, obj, pos_y, pos_x);
// }
void compare_map(sys_t *sys)
{
	int pos_y = 0;
	int pos_x = 0;
	int obj = 0;

	while (pos_y != 10) {
		while (sys->map[pos_y][pos_x] != '\n') {
			switch (sys->map[pos_y][pos_x]) {
				case '1':
					obj++;
					init_ground(sys, obj, pos_y, pos_x);
					break;
				case '2':
					obj++;
					init_dirt(sys, obj, pos_y, pos_x);
					break;
				case '3':
					obj++;
					init_water(sys, obj, pos_y, pos_x);
					break;
				case 'T':
					obj++;
					init_square_tree(sys, obj, pos_y, pos_x);
					break;
				case 'F':
					obj++;
					init_tree(sys, obj, pos_y, pos_x);
					break;
				case 'O':
					obj++;
					init_obstacles(sys, obj, pos_y, pos_x);
					break;
				case 'S':
					obj++;
					init_saw(sys, obj, pos_y, pos_x);
					break;
				case 'M':
					obj++;
					init_mace(sys, obj, pos_y, pos_x);
					break;
			}
			pos_x++;
		}
		pos_y++;
		pos_x = 0;
	}
}
