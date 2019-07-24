/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:00:08 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/24 16:27:01 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corvm.h"

void	new_op(t_vm *vm, t_proc *proc, t_op op_tab[17])
{
	proc->command_type = vm->arena[proc->pos];
	if (proc->command_type < 17 && proc->command_type > 0)
		proc->cycles_to_wait = op_tab[proc->command_type].cycles_wait;
	else
		proc->cycles_to_wait = 0;
}

int		get_arg(int octet, int k, int p)
{
	return (((1 << k) - 1) & (octet >> (p - 1)));
}

int		arg_check(unsigned char octet, const t_op op)
{
	int	i;
	unsigned char arg;

	i = 0;
	while (i < op.number)
	{
		arg = get_arg(octet, 2, 7 - i * 2);
		if (arg == 3)
			arg++;
		if (!(arg & op.types_arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int		get_arg_size(int arg_type, t_op op)
{
	if (arg_type == T_REG)
		return (1);
	else if (arg_type == 3)
		return (2);
	else if (arg_type == T_DIR)
		return (op.is_short_dir ? 2 : 4);
	else
		return (0);
}

int		get_pos(int pos, t_op op, unsigned int octet)
{
	int	new_pos;
	int	i;
	int	arg;

	new_pos = pos + 1;
	if (op.coding_byte)
	{
		new_pos += 1;
		i = 0;
		while (i < op.number)
		{
			arg = get_arg(octet, 2, 7 - i * 2);
			new_pos += get_arg_size(arg, op);
			i++;
		}
		return (new_pos % MEM_SIZE);
	}
	i = 0;
	while (i < op.number)
	{
		new_pos += get_arg_size(op.types_arg[i], op);
		i++;
	}
	return (new_pos % MEM_SIZE);
}

int		check_reg1(unsigned int octet)
{
	if (get_arg(octet, 2, 7) == T_REG)
		return (1);
	if (get_arg(octet, 2, 5) == T_REG)
		return (1);
	if (get_arg(octet, 2, 3) == T_REG)
		return (1);
	return (0);
}

int		check_reg(unsigned int octet, unsigned char	arena[MEM_SIZE], int pos, t_op op)
{
	int	i;
	int	tmp_pos;
	int	arg_type;

	i = 0;
	tmp_pos = (pos + 1) % MEM_SIZE;
	if (!check_reg1(octet))
		return (0);
	while (i < op.number)
	{
		arg_type = get_arg(octet, 2, 7 - i * 2);
		if (arg_type == T_REG)
		{
			if (arena[tmp_pos] < 1 || arena[tmp_pos] > 16)
				return (1);
		}
		tmp_pos = (tmp_pos + get_arg_size(arg_type, op)) % MEM_SIZE;
		i++;
	}
	return (0);
}

void	do_proc(t_vm *vm, t_proc *proc, void (*f[17])(t_vm *, t_proc *), t_op op_tab[17])
{
	unsigned int	type;

	if (op_tab[proc->command_type].coding_byte)
	{
		type = vm->arena[(proc->pos + 1) % MEM_SIZE];
		if (arg_check(type, op_tab[proc->command_type]))
		{
			if (!check_reg(type, vm->arena, proc->pos, op_tab[proc->command_type]))
				proc->pos = get_pos(proc->pos, op_tab[proc->command_type], type);	
			else
			{
				f[proc->command_type](vm, proc);
				proc->pos = get_pos(proc->pos, op_tab[proc->command_type], type);
			}
		}
		else
			proc->pos = get_pos(proc->pos, op_tab[proc->command_type], type);	
	}
	else
		f[proc->command_type](vm, proc);
}

void	init_func(void (*f[17])(t_vm *, t_proc *))
{
	f[1] = &op_live;
	f[2] = &op_ld;
	f[3] = &op_st;
	f[4] = &op_add;
	f[5] = &op_sub;
	f[6] = &op_and;
	f[7] = &op_or;
	f[8] = &op_xor;
	f[9] = &op_zjmp;
	f[10] = &op_ldi;
	f[11] = &op_sti;
	f[12] = &op_fork;
	f[13] = &op_lld;
	f[14] = &op_lldi;
	f[15] = &op_lfork;
	f[16] = &op_aff;
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
		if (proccess->cycles_to_wait > 0)
			proccess->cycles_to_wait -= 1;
		if (!proccess->cycles_to_wait && proccess->command_type < 17
			&& proccess->command_type > 0)
			do_proc(vm, proccess, f, op_tab);			
		else if (!proccess->cycles_to_wait)
		{
			proccess->pos += 1;
			proccess->pos %= MEM_SIZE;
		}
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
		if (vm->cycles - curr->live >= CYCLE_TO_DIE)
			proccess_kill(head, curr);
		curr = curr->next;
	}
	if (*head == NULL)
		vm->winner = 1;
}

void	champions_reset_lives(t_champ *champs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		champs[i].live = 0;
		i++;
	}
}

void    play_game(t_vm *vm, t_op op_tab[17])
{
	performe_proc(vm, vm->list_process, op_tab);
	if (!vm->cycles_to_die)
	{
		check_live(vm, &vm->list_process);
		if (vm->l_exec >= NBR_LIVE || vm->checks >= MAX_CHECKS)
		{
			vm->cycles_die -= CYCLE_DELTA;
			vm->checks = 1;
			if (vm->cycles_die <= 0)
			{
				vm->winner = 1;
				vm->cycles++;
			}
		}
		else
			vm->checks += 1;
		vm->cycles_to_die = vm->cycles_die;
		vm->l_exec = 0;
		champions_reset_lives(vm->champs, vm->champ_nb);
	}
	if (vm->winner != 1)
		vm->cycles += 1;
	vm->cycles_to_die -= 1;
}
