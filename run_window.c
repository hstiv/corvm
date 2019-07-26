/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:11:41 by mwuckert          #+#    #+#             */
/*   Updated: 2019/04/12 19:25:15 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.h"

void			get_x_y(t_dot *n1, t_proc *proc)
{
	int 		tmp;

	tmp = proc->pos;
	n1->y = 0;
	while (tmp >= BIT_LENTH)
	{
		tmp -= BIT_LENTH;
		n1->y++;
	}
	n1->x = (tmp * 25) + 10;
	n1->y = (n1->y * 20) + 10;
}

void			draw_carriage(t_vm *vm)
{
	t_dot		n1;
	t_dot		n2;
	t_dot		n;
	t_proc		*tmp;

	tmp = vm->list_process;
	while (tmp)
	{
		get_x_y(&n, tmp);
		set_corrage_cor(&n1, &n2, &n, 1);
		ft_bresenham(&n1, &n2, vm->mlx, GREEN);
		set_corrage_cor(&n1, &n2, &n, 2);
		ft_bresenham(&n1, &n2, vm->mlx, GREEN);
		set_corrage_cor(&n1, &n2, &n, 3);
		ft_bresenham(&n1, &n2, vm->mlx, GREEN);
		set_corrage_cor(&n1, &n2, &n, 4);
		ft_bresenham(&n1, &n2, vm->mlx, GREEN);
		tmp = tmp->next;
	}
}

void				draw_arena(t_vm *vm, int *i, int *x, int y)
{
	char 			*s;
	int 			t;

	t = vm->champ_nb - 1;
	while ((*i + 1) % BIT_LENTH != 0 && *i < MEM_SIZE)
	{
		(vm->champs[t].pos >= *(i) + 1) ? t-- : 0;
		s = itoa_base(vm->arena[*i], 16);
		add_zero_to_string(&s);
		mlx_string_put(vm->mlx->ptr, vm->mlx->wind,
							*x, y, ch_col(vm, *i, t), s);
		(*x) += 25;
		free(s);
		(*i)++;
	}
}

void				put_man(t_vm *vm)
{
	void			*pv;

	pv = (void*)vm;
}

void				putarenainwindow(t_vm *vm)
{
	int				i;
	int				y;
	int				x;

	i = 0;
	y = 10;
	mlx_clear_window(vm->mlx->ptr, vm->mlx->wind);
	while (i < MEM_SIZE)
	{
		x = 10;
		draw_arena(vm, &i, &x, y);
		y += 20;
		i++;
	}
	draw_carriage(vm);
	put_man(vm);
}
