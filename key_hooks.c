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
		mlx->mseconds -= 100000;
	if (keycode == 123)
		mlx->mseconds += 100000;
}

int				key_press(int keycode, t_mlx *mlx)
{
	t_vm		*vm;

	vm = mlx->vm;
	speed_change(keycode, mlx);
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
	if (keycode == 49)
		mlx->pause++;
	return (1);
}
