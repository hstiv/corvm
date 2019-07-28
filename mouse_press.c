//
// Created by Hallie Stiv on 2019-07-28.
//

#include "corvm.h"

int 					mouse_press(int keycode, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	if (keycode == 4 && mlx->c_button % 2)
		mlx->man_y += 5;
	if (keycode == 5 && mlx->c_button % 2)
		mlx->man_y -= 5;
	if (keycode == 4 && mlx->x_button % 2)
		mlx->ar_y += 5;
	if (keycode == 5 && mlx->x_button % 2)
		mlx->ar_y -= 5;
	return (1);
}