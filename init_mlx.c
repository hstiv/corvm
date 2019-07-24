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

#include "corvm.h"

void		init_mlx(t_vm *vm)
{
	t_mlx	data;

	vm->mlx = &data;
	vm->mlx->ptr = mlx_init();
	vm->mlx->wind = mlx_new_window(vm->mlx->ptr, WIDTH, HEIGHT, WIND);
	vm->mlx->vm = vm;
	vm->mlx->pause = 0;
	vm->mlx->err = 0;
	vm->mlx->derr = 0;
	vm->mlx->mseconds = 10;
}
