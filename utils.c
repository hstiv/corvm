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

char			*itoa_base(int value, int base)
{
	char	*s;
	long	n;
	int		sign;
	int		i;

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
