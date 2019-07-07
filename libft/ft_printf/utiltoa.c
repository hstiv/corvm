/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:48:31 by sdiedra           #+#    #+#             */
/*   Updated: 2019/05/31 16:16:54 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

int				ft_num_len(unsigned long long n, int base)
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

char			*ft_ullitoa_base(unsigned long long num,
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

static size_t	ft_ullnumlen(unsigned long long n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static void		ft_ullitoa_inner(unsigned long long n, size_t len, char *buf)
{
	char	*ptr;

	ptr = buf;
	while (len)
	{
		ptr[len - 1] = n % 10 + '0';
		n /= 10;
		--len;
	}
}

char			*ft_ullitoa(unsigned long long n)
{
	char	*newstr;
	size_t	len;

	len = ft_ullnumlen(n);
	if (n == 0)
		len = 1;
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	ft_ullitoa_inner(n, len, newstr);
	newstr[len] = '\0';
	return (newstr);
}
