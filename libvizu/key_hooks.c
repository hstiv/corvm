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

#include "libvizu.h"

int				ft_close(void *param)
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

static void		pause_game(int keycode, t_mlx *mlx)
{
	int 		i;

	i = 0;
	mlx->pause++;
	while (mlx->pause % 2 != 0)
	{
		i++;
		mlx_hook(mlx->wind, 2, 0, key_press, mlx);
		mlx_loop(mlx->ptr);
	}
}

int				key_press(int keycode, t_mlx *mlx)
{
	speed_change(keycode, mlx);
	if (keycode == 49)
		pause_game(keycode);
	return (0);
}
