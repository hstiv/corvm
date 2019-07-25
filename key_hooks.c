/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:29:09 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 14:29:10 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.h"

int				expose_hook(void *param)
{
	t_mlx		*tmp;

	tmp = (t_mlx *)param;
	exit(0);
}

static void		speed_change(int keycode, t_mlx *mlx)
{
	if (keycode == 124)
		mlx->mseconds--;
	if (keycode == 123)
		mlx->mseconds++;
}

//static void		pause_game(t_mlx *mlx)
//{
//	int 		i;
//
//	i = 0;
//	mlx->pause++;
//	while (mlx->pause % 2 != 0)
//	{
//		i++;
//		mlx_hook(mlx->wind, 2, 0, key_press, mlx);
//		mlx_loop(mlx->ptr);
//	}
//}

int				key_press(int keycode, t_mlx *mlx)
{
	t_vm		*vm;

	vm = mlx->vm;
	speed_change(keycode, mlx);
//	if (keycode == 49)
//		pause_game(mlx);
	if (keycode == 53)
	{
		if (vm->winner)
		{
			mlx_destroy_window(vm->mlx->ptr, vm->mlx->wind);
			ft_printf("Contestant %d, \"%s\", has won !\n",
					  vm->winner_n, vm->champs[vm->winner_n - 1].name);
		}
		threw("");
	}
	return (0);
}
