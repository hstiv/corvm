/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:35:23 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/14 17:03:12 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.c"

void	add(t_proc *proc, t_vm *vm)
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
