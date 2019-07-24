/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:16:40 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/24 18:17:30 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corvm.h"

int				reverse_bytes(t_vm *vm, unsigned int pc, int nbytes)
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

int				ft_isdigit_s(char *s)
{
	int				i;

	i = (s[0] == '-') ? 1 : 0;
	while (s[i])
	{
		if (!(s[i] >= 48 && s[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}
