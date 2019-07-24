/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:19:43 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/24 18:21:08 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corvm.h"

t_proc		*new_proc(int player_id, int pos)
{
	t_proc	*new_pr;
	int		i;

	i = -1;
	new_pr = (t_proc *)malloc(sizeof(t_proc));
	if (!new_pr)
		return (NULL);
	while (++i < REG_NUMBER)
		new_pr->reg[i] = 0;
	new_pr->reg[0] = -player_id;
	new_pr->carry = 0;
	new_pr->pos = pos;
	new_pr->cycles_to_wait = 0;
	new_pr->player_id = player_id;
	new_pr->live = 0;
	new_pr->next = NULL;
	return (new_pr);
}

void		proccess_add(t_proc **head, t_proc *new_p)
{
	if (head && new_p)
	{
		new_p->next = *head;
		*head = new_p;
	}
}

void		init_proc(t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->champ_nb)
	{
		proccess_add(&vm->list_process, new_proc(vm->champs[i].n_place,
					vm->champs[i].pos));
		i++;
	}
}

void		arena(t_vm *vm)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i < vm->champ_nb)
	{
		ft_memcpy(&(vm->arena[n]),
			vm->champs[i].champ_bin, vm->champs[i].exec_code);
		ft_memset(&(vm->owner[n]), i + 1, vm->champs[i].exec_code);
		vm->champs[i].pos = n;
		n += MEM_SIZE / vm->champ_nb;
		i++;
	}
	init_proc(vm);
}
