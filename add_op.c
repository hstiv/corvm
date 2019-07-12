/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:35:23 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/12 17:39:23 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.c"

void	add(t_proc *proc, t_vm *vm)
{
	int	first;
	int second;
	int	res;

	first = proc->reg[vm->arena[proc->pos + 1 % MEM_SIZE]];
	second = proc->reg[vm->arena[proc->pos + 2 % MEM_SIZE]];
	res = first + second;
	proc->reg[vm->arena[proc->pos + 3 % MEM_SIZE]] = res;
	if (!res)
		proc->carry = 1;
	else
		proc->carry = 0;
}
