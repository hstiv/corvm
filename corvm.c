/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corvm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:25:29 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/24 18:24:39 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.h"

void				threw(char *s)
{
	write(1, s, ft_strlen(s));
	exit(0);
}

void				introduce_players(t_vm *vm)
{
	int				i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < vm->champ_nb)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",\
		vm->champs[i].n_place, vm->champs[i].exec_code, vm->champs[i].name,
								vm->champs[i].comment);
		i++;
	}
}

void                main_cycle_vizu(t_vm *vm, t_op *op)
{
	if (vm->winner)
	{
		mlx_destroy_window(vm->mlx->ptr, vm->mlx->wind);
		ft_printf("Contestant %d, \"%s\", has won !\n",
				  vm->winner_n, vm->champs[vm->winner_n - 1].name);
		threw("");
	}
	play_game(vm, op);
	if (vm->cycles == vm->dump_cycles)
		show_dump(vm);
	play_game(vm, op);
	mlx_hook(vm->mlx->wind, 17, (1L << 17), expose_hook, vm->mlx);
	mlx_hook(vm->mlx->wind, 2, 0, key_press, vm->mlx);
	putarenainwindow(vm, vm->mlx);
	mlx_loop(vm->mlx->ptr);
}

int					main(int c, char **s)
{
	t_vm			vm;
	t_op			op[17];

	new_vm(&vm);
	init_op(op);
	if (c == 1)
		threw(USAGE);
	parser(c, s, &vm);
	arena(&vm);
	introduce_players(&vm);
	if (!vm.mlx)
	{
		while (!vm.winner)
		{
			play_game(&vm, op);
			if (vm.cycles == vm.dump_cycles)
				show_dump(&vm);
			play_game(&vm, op);
		}
		ft_printf("Contestant %d, \"%s\", has won !\n",
				  vm.winner_n, vm.champs[vm.winner_n - 1].name);
    }
	else
		main_cycle_vizu(&vm, op);
	return (0);
}
