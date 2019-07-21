/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:06:27 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/12 17:06:28 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_base(char c)
{
	char		*s1;
	char		*s2;
	int			i;

	s1 = "0123456789abcdef";
	s2 = "0123456789ABCDEF";
	i = 0;
	while (i < 16)
	{
		if (s1[i] == c || s2[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int		white_spaces(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int				ft_atoi_base(char *s, int base)
{
	int			res;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	res = 0;
	while (white_spaces(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		(s[i] == '-') ? sign = -1 : 0;
		i++;
	}
	while (is_base(s[i]) >= 0)
	{
		res *= base;
		res += is_base(s[i]);
		i++;
	}
	return (res * sign);
}
