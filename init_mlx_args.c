/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:29:32 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/31 14:29:44 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.h"

void		init_mlx_args(t_vm *vm)
{
	vm->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (vm->mlx)
	{
		vm->mlx->ptr = mlx_init();
		vm->mlx->wind = mlx_new_window(vm->mlx->ptr, WIDTH, HEIGHT, WIND);
		vm->mlx->pause = 0;
		vm->mlx->err = 0;
		vm->mlx->derr = 0;
		vm->mlx->mseconds = 1000000;
		vm->mlx->now = 0;
		vm->mlx->op = NULL;
		vm->mlx->ply_man[0] = PLYR1;
		vm->mlx->ply_man[1] = PLYR2;
		vm->mlx->ply_man[2] = PLYR3;
		vm->mlx->ply_man[3] = PLYR4;
		vm->mlx->speed = 10;
	}
}
