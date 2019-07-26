/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:55:58 by hstiv             #+#    #+#             */
/*   Updated: 2019/07/21 17:56:05 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.h"

void				threw(char *s)
{
	(s != NULL) ? write(1, s, ft_strlen(s)) : 0;
	exit(0);
}

void				set_corrage_cor(t_dot *n1, t_dot *n2, t_dot *n, int i)
{
	n1->x = n->x;
	n1->y = n->y;
	n2->x = n->x;
	n2->y = n->y;
	if (i == 1)
		n2->y += 20;
	else if (i == 2)
	{
		n1->x += 20;
		n2->x += 20;
		n2->y += 20;
	}
	else if (i == 3)
		n2->x = n->x + 20;
	else if (i == 4)
	{
		n1->y += 20;
		n2->x += 20;
		n2->y += 20;
	}
}

char				*itoa_base(int value, int base)
{
	char			*s;
	long			n;
	int				sign;
	int				i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

void				add_zero_to_string(char **s1)
{
	char 			*s;
	char 			*tmp;

	if (ft_strlen(*s1) < 2)
	{
		s = (char *)malloc(sizeof(char) * 3);
		if (s)
		{
			s[0] = '0';
			s[1] = *s1[0];
			s[2] = '\0';
		}
		tmp = *s1;
		*s1 = s;
		free(tmp);
	}
}

int 				ch_col(t_vm *vm, int i, int t)
{
	int 			err;

	err = i + 1 - (vm->champs[t].pos + vm->champs[t].exec_code);
	if (err > 0)
		return (WHITE);
	return (vm->colors[t]);
}
