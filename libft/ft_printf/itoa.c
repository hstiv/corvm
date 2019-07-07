/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:44:56 by sdiedra           #+#    #+#             */
/*   Updated: 2019/05/31 16:16:38 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

static size_t	ft_numlen(long long int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		++len;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

static void		ft_itoa_inner(long long int n, size_t len, char *buf)
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

char			*ft_llitoa(long long int n)
{
	char			*newstr;
	size_t			len;
	int				sign;

	sign = n >= (long long)0 ? 0 : 1;
	len = ft_numlen(n);
	if (n == 0)
		len = 1;
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	if (n < -9223372036854775807)
	{
		ft_strcpy(newstr, "-9223372036854775808");
		return (newstr);
	}
	if (sign)
		n *= -1;
	ft_itoa_inner(n, len, newstr);
	if (sign)
		newstr[0] = '-';
	newstr[len] = '\0';
	return (newstr);
}
