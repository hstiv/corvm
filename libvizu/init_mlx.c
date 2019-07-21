/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:29:32 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 14:29:44 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvizu.h"

void		init_mlx(t_mlx *mlx, t_vm *vm)
{
	t_mlx	data;

	mlx = &data;
	mlx->ptr = mlx_init();
	mlx->wind = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "Corewar: Angel Arena");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->vm = vm;
	mlx->mseconds = 10;
}
