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

#include "libvizu.h"

void			dynamic_clear(char *s, int n)
{
	int			i;

	i = 0;
	while (i < n)
		s[i++] = '\0';
}

static int		ft_num_len(unsigned long long n, int base)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= base;
		len += 1;
	}
	return (len);
}

char			*itoa_base(unsigned long long num,
								const char *sym, int base)
{
	char	*str;
	int		len;

	len = ft_num_len(num, base);
	if (num == 0)
		len = 1;
	if ((str = ft_strnew((size_t)len)) == NULL)
		return (NULL);
	while (len - 1 >= 0)
	{
		str[len - 1] = sym[num % base];
		num /= base;
		len--;
	}
	return (str);
}
