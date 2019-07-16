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

# define ARENA(x)	v->arena[(unsigned int)(x) % MEM_SIZE]

int		reverse_bytes(t_vm *v, unsigned int pc, int nbytes)
{
	unsigned char two_bytes[2];
	unsigned char four_bytes[4];

	if (nbytes == 2)
	{
		two_bytes[0] = ARENA(pc + 1);
		two_bytes[1] = ARENA(pc);
		return (*(short *)&two_bytes[0]);
	}
	if (nbytes == 4)
	{
		four_bytes[0] = ARENA(pc + 3);
		four_bytes[1] = ARENA(pc + 2);
		four_bytes[2] = ARENA(pc + 1);
		four_bytes[3] = ARENA(pc);
		return (*(int *)&four_bytes[0]);
	}
	return (-1);
}

void	add(t_vm *vm, t_proc *proc)
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

void	sub(t_vm *vm, t_proc *proc)
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

void	and(t_vm *vm, t_proc *proc)
{

}

void	load(t_vm *vm, t_proc *proc)
{
	
}

void	live(t_vm *vm, t_proc *proc)
{
	int	arg;

	arg = reverse_bytes(vm, proc->pos + 1, 4);
	if (proc->reg[0] == proc->player_id)
		proc->live = 1;
	proc->pos += 5;
	proc->pos %= MEM_SIZE;
}


void	zjmp(t_vm *vm, t_proc *proc)
{
	int	arg;

	arg = reverse_bytes(vm, proc->pos, 2);
	arg %= IDX_MOD;
	if (proc->carry == 1)
		proc->pos += arg % MEM_SIZE;
	else
		proc->pos += 3 % MEM_SIZE;
}