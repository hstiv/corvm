/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:00:08 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/14 17:58:27 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.h"

void	new_op(t_vm *vm, t_proc *proc, t_op op_tab[17])
{
	proc->command_type = vm->arena[proc->pos];
	if (proc->command_type < 17 && proc->command_type > 0)
		proc->cycles_to_wait = op_tab[proc->command_type].cycles_wait;
	else
		proc->cycles_to_wait = 0;
}

int		byte_check(unsigned char octet, const t_op op)
{

}


void	do_proc(t_vm *vm, t_proc *proc, void (*f[17])(t_vm *, t_proc *), t_op op_tab[17])
{
	unsigned int	type;

	if (op_tab[proc->command_type].coding_byte)
	{
		type = vm->arena[(proc->pos + 1) % MEM_SIZE];
		if (byte_check(type, op_tab[proc->command_type]))
		{

		}

	}
	else
		f[proc->command_type](vm, proc);
}

void	init_func(void (*f[17])(t_vm *, t_proc *))
{
	f[4] = &add;
}

void	performe_proc(t_vm *vm, t_proc *head, t_op op_tab[17])
{
	t_proc	*proccess;
	void	(*f[17])(t_vm *, t_proc *);

	proccess = head;
	init_func(f);
	while (proccess)
	{
		if (!proccess->cycles_to_wait)
			new_op(vm, proccess, op_tab);
		if (proccess->cycles_to_wait)
			proccess->cycles_to_wait -= 1;
		if (!proccess->cycles_to_wait && proccess->command_type < 17
			&& proccess->command_type > 0)
			do_proc(vm, proccess, f, op_tab);			
		else if (!proccess->cycles_to_wait)
			proccess->pos += 1;
		proccess = proccess->next;
	}
}

void		proccess_kill(t_proc **head, t_proc *ps)
{
	t_proc	*prev;
	t_proc	*curr;

	if (!head || !ps)
		return ;
	curr = *head;
	if (curr == ps)
	{
		(*head) = (*head)->next;
		free(curr);
		return ;
	}
	while (curr && curr != ps)
	{
		prev = curr;
		curr = curr->next;
	}
	if (!curr)
		return ;
	prev->next = curr->next;
	free(curr);
}

void	check_live(t_vm *vm, t_proc **head)
{
	t_proc	*curr;

	if (!head)
		return ;
	curr = *head;
	while (curr)
	{
		if (vm->cycles - curr->live >= vm->cycles_to_die)
		{
			proccess_kill(head, curr);
		}
		curr = curr->next;
	}
	if (*head == NULL)
		vm->winner = 1;
}

void    play_game(t_vm *vm, t_op op_tab[17])
{
	performe_proc(vm, vm->list_process, op_tab);
	if (!vm->cycles_to_die)
	{
		check_live(vm, &vm->list_process);
		if (vm->l_exec >= NBR_LIVE || vm->checks >= MAX_CHECKS)
		{
			vm->cycles_to_die -= CYCLE_DELTA;
			vm->checks = 1;
			if (vm->cycles_to_die <= 0)
			{
				vm->winner = 1;
				vm->cycles++;
			}
		}
		else
			vm->checks += 1;
		vm->l_exec = 0;
	}
	if (!vm->winner)
		vm->cycles;
	vm->cycles_to_die--;
}
