/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corvm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 14:25:29 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/12 17:01:35 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.h"

void	threw(char *s)
{
	write(1, s, ft_strlen(s));
	exit(0);
}

void	introduce_players(t_vm *vm)
{
	int	i;

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

int		main(int c, char **s)
{
	t_vm	vm;
	t_op	op[17];

	new_vm(&vm);
	init_op(op);
	if (c == 1)
		threw(USAGE);
	parser(c, s, &vm);
	arena(&vm);
	introduce_players(&vm);
	while (!vm.winner)
	{
		play_game(&vm, op);
		if (vm.cycles == vm.dump_cycles)
			show_dump(&vm);
	}
	ft_printf("Player %d (%s) won\n", vm.winner, vm.winner_name);
	return (0);
}
