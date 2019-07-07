/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:27:06 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/03 18:42:56 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ch_len(long i)
{
	size_t	len;

	len = 0;
	if (i <= 0)
	{
		len++;
		i *= -1;
	}
	while (i)
	{
		i /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	i;
	int		j;

	i = (long)n;
	len = ch_len(i);
	if (!(str = ft_strnew(len)))
		return (NULL);
	j = len;
	i = (long)n;
	if (i < 0)
	{
		str[0] = '-';
		i *= -1;
	}
	if (i == 0)
		str[0] = '0';
	while (--j >= 0)
	{
		if (str[j] != '-' && str[0] != '0')
			str[j] = i % 10 + '0';
		i /= 10;
	}
	return (str);
}
