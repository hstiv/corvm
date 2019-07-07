/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:58:08 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/23 19:41:19 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strlen_w(char const *str, int a, char c)
{
	int	i;

	i = 0;
	while (str[a] && !(str[a] == c))
	{
		a++;
		i++;
	}
	return (i);
}

static char	*ft_strncpy_a(char *dest, char const *src, int a, int n)
{
	int	i;
	int	j;

	j = 0;
	i = a;
	while (src[i] != '\0' && i < n + a)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static int	nmbr_of_w(char const *str, char c)
{
	int	count;
	int	w;
	int	i;

	i = 0;
	w = 0;
	count = 0;
	while (str[i])
	{
		if (!(str[i] == c) && !w)
		{
			count++;
			w = 1;
		}
		if (str[i] == c)
			w = 0;
		i++;
	}
	return (count);
}

static char	**del_2arr(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	av = NULL;
	return (av);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**mas_str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (!(mas_str = (char **)malloc(sizeof(char *) * nmbr_of_w(s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if (!(mas_str[j] = ft_strnew(ft_strlen_w(s, i, c))))
				return (del_2arr(mas_str));
			ft_strncpy_a(mas_str[j], s, i, ft_strlen_w(s, i, c));
			i += ft_strlen_w(s, i, c);
			j++;
		}
	}
	mas_str[j] = NULL;
	return (mas_str);
}
