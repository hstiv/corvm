/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:35:23 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/16 17:19:36 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.h"

int		reverse_bytes(t_vm *vm, unsigned int pc, int nbytes)
{
	unsigned char two_bytes[2];
	unsigned char four_bytes[4];

	if (nbytes == 2)
	{
		two_bytes[0] = vm->arena[(pc + 1) % MEM_SIZE];
		two_bytes[1] = vm->arena[pc % MEM_SIZE];
		return (*(short *)&two_bytes[0]);
	}
	if (nbytes == 4)
	{
		four_bytes[0] = vm->arena[(pc + 3) % MEM_SIZE];
		four_bytes[1] = vm->arena[(pc + 2) % MEM_SIZE];
		four_bytes[2] = vm->arena[(pc + 1) % MEM_SIZE];
		four_bytes[3] = vm->arena[pc % MEM_SIZE];
		return (*(int *)&four_bytes[0]);
	}
	return (-1);
}

void	op_live(t_vm *vm, t_proc *proc)
{
	int			number;

	number = reverse_bytes(vm, proc->pos + 1, 4);
	proc->live = vm->cycles;
	if (-number > 0 && -number <= vm->champ_nb)
	{
		vm->winner_n = vm->champs[-number - 1].n_place;
		vm->champs[-number - 1].lives_in_period++;
		vm->champs[-number - 1].live = vm->cycles;
	}
	proc->pos += 5;
	proc->pos %= MEM_SIZE;
	vm->l_exec += 1;;
}

void	op_ld(t_vm *vm, t_proc *proc)
{
	int	type;
	int	n_pos;
	int	number;

	if ((type = get_arg(vm->arena[(proc->pos + 1) % MEM_SIZE], 2, 7)) == T_DIR)
		n_pos = (proc->pos + 2) % MEM_SIZE;
	else
	{
		n_pos = reverse_bytes(vm, proc->pos + 2, 2) % IDX_MOD;
		n_pos = (n_pos + proc->pos) % MEM_SIZE;
	}
	number = reverse_bytes(vm, n_pos, 4);
	if (!number)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (type == T_DIR)
		proc->reg[vm->arena[(proc->pos + 2 + 4) % MEM_SIZE] - 1] = number;
	else
		proc->reg[vm->arena[(proc->pos + 2 + 4) % MEM_SIZE] - 1] = number;
}

void	op_st(t_vm *vm, t_proc *proc)
{
	int		type;
	int		number;
	int		index;
	int		i;

	number = proc->reg[vm->arena[(proc->pos + 2) % MEM_SIZE] - 1];
	type = get_arg(vm->arena[(proc->pos + 1) % MEM_SIZE], 2, 5);
	if (type == T_REG)
		proc->reg[vm->arena[(proc->pos + 3) % MEM_SIZE] - 1] = number;
	else
	{
		index = reverse_bytes(vm, proc->pos + 3, 2);
		index = (index + proc->pos) % MEM_SIZE;
		i = 0;
		while (i < REG_SIZE)
		{
			vm->arena[(index + REG_SIZE - i - 1) % MEM_SIZE] = (number >> (i * 8));
			i++;
		}
	}
}

void	op_add(t_vm *vm, t_proc *proc)
{
	int	first;
	int second;
	int	res;

	first = proc->reg[vm->arena[(proc->pos + 2) % MEM_SIZE] - 1];
	second = proc->reg[vm->arena[(proc->pos + 3) % MEM_SIZE] - 1];
	res = first + second;
	proc->reg[vm->arena[(proc->pos + 4) % MEM_SIZE] - 1] = res;
	if (!res)
		proc->carry = 1;
	else
		proc->carry = 0;
}

void	op_sub(t_vm *vm, t_proc *proc)
{
	int	first;
	int second;
	int	res;

	first = proc->reg[vm->arena[(proc->pos + 2) % MEM_SIZE] - 1];
	second = proc->reg[vm->arena[(proc->pos + 3) % MEM_SIZE] - 1];
	res = first - second;
	proc->reg[vm->arena[(proc->pos + 4) % MEM_SIZE] - 1] = res;
	if (!res)
		proc->carry = 1;
	else
		proc->carry = 0;
}

void	op_and(t_vm *vm, t_proc *proc)
{
	int		type;
	int		i;
	int		j;
	int		args[3];

	i = -1;
	j = 0;
	while (++i < 2)
	{
		type = get_arg(vm->arena[(proc->pos + 1) % MEM_SIZE], 2, 7 - 2 * i);
		if (type == T_REG)
			args[i] = proc->reg[vm->arena[(proc->pos + 2 + j) % MEM_SIZE] - 1];
		else if (type == T_DIR)
			args[i] = reverse_bytes(vm, proc->pos + 2 + j, 4) % MEM_SIZE;
		else
		{
			args[i] = reverse_bytes(vm, proc->pos + 2 + j, 2) % IDX_MOD;
			args[i] = (args[i] + proc->pos) % MEM_SIZE;
			args[i] = reverse_bytes(vm, args[i], 4);
		}
		if (type == T_DIR)
			j += 4;
		else if (type == T_REG)
			j += 1;
		else
			j += 2;
	}
	args[2] = vm->arena[(proc->pos + 2 + j) % MEM_SIZE] - 1;
	proc->reg[args[2]] = args[0] & args[1];
	proc->carry = (proc->reg[args[2]] != 0) ? 0 : 1;
}

void	op_or(t_vm *vm, t_proc *proc)
{
	int		type;
	int		i;
	int		j;
	int		args[3];

	i = -1;
	j = 0;
	while (++i < 2)
	{
		type = get_arg(vm->arena[(proc->pos + 1) % MEM_SIZE], 2, 7 - 2 * i);
		if (type == T_REG)
			args[i] = proc->reg[vm->arena[(proc->pos + 2 + j) % MEM_SIZE] - 1];
		else if (type == T_DIR)
			args[i] = reverse_bytes(vm, proc->pos + 2 + j, 4) % MEM_SIZE;
		else
		{
			args[i] = reverse_bytes(vm, proc->pos + 2 + j, 2) % IDX_MOD;
			args[i] = (args[i] + proc->pos + 2 + j) % MEM_SIZE;
			args[i] = reverse_bytes(vm, args[i], 4);
		}
		if (type == T_DIR)
			j += 4;
		else if (type == T_REG)
			j += 1;
		else
			j += 2;
	}
	args[2] = vm->arena[(proc->pos + 2 + j) % MEM_SIZE] - 1;
	proc->reg[args[2]] = args[0] | args[1];
	proc->carry = (proc->reg[args[2]] != 0) ? 0 : 1;
}

void	op_xor(t_vm *vm, t_proc *proc)
{
	int		type;
	int		i;
	int		j;
	int		args[3];

	i = -1;
	j = 0;
	while (++i < 2)
	{
		type = get_arg(vm->arena[(proc->pos + 1) % MEM_SIZE], 2, 7 - 2 * i);
		if (type == T_REG)
			args[i] = proc->reg[vm->arena[(proc->pos + 2 + j) % MEM_SIZE] - 1];
		else if (type == T_DIR)
			args[i] = reverse_bytes(vm, proc->pos + 2 + j, 4) % MEM_SIZE;
		else
		{
			args[i] = reverse_bytes(vm, proc->pos + 2 + j, 2) % IDX_MOD;
			args[i] = (args[i] + proc->pos + 2 + j) % MEM_SIZE;
			args[i] = reverse_bytes(vm, args[i], 4);
		}
		if (type == T_DIR)
			j += 4;
		else if (type == T_REG)
			j += 1;
		else
			j += 2;
	}
	args[2] = vm->arena[(proc->pos + 2 + j) % MEM_SIZE] - 1;
	proc->reg[args[2]] = args[0] ^ args[1];
	proc->carry = (proc->reg[args[2]] != 0) ? 0 : 1;
}


void	op_zjmp(t_vm *vm, t_proc *proc)
{
	int	arg;

	arg = reverse_bytes(vm, proc->pos + 1, 2);
	arg %= IDX_MOD;
	if (proc->carry == 1)
		proc->pos = (proc->pos + arg) % MEM_SIZE;
	else
		proc->pos = (proc->pos + 3) % MEM_SIZE;
}

void	op_ldi(t_vm *vm, t_proc *proc)
{
	(void)vm;
	(void)proc;
}

void	op_sti(t_vm *vm, t_proc *proc)
{
	(void)vm;
	(void)proc;
}

void	op_fork(t_vm *vm, t_proc *proc)
{
	int arg;

	arg = reverse_bytes(vm, proc->pos + 1, 2) % IDX_MOD;
	arg = (arg + proc->pos) % MEM_SIZE;
	proccess_add(&vm->list_process, new_proc(vm->list_process->player_id, arg));
	vm->list_process->carry = proc->carry;
	vm->list_process->live = proc->live;
	proc->pos = (proc->pos + 3) % MEM_SIZE;
}
void	op_lld(t_vm *vm, t_proc *proc)
{
	(void)vm;
	(void)proc;
}
void	op_lldi(t_vm *vm, t_proc *proc)
{
	(void)vm;
	(void)proc;
}
void	op_lfork(t_vm *vm, t_proc *proc)
{
	int arg;

	arg = reverse_bytes(vm, proc->pos + 1, 2);
	arg = (arg + proc->pos) % MEM_SIZE;
	proccess_add(&vm->list_process, new_proc(vm->list_process->player_id, arg));
	vm->list_process->carry = proc->carry;
	vm->list_process->live = proc->live;
	proc->pos = (proc->pos + 3) % MEM_SIZE;
}

void	op_aff(t_vm *vm, t_proc *proc)
{
	int		i;

	i = vm->arena[(proc->pos + 2) % MEM_SIZE] - 1;
	ft_printf("%c", (char)proc->reg[i]);
}