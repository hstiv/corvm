/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:08:58 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/04 19:38:30 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	j;
	size_t	i;

	if (!*to_find)
		return ((char *)str);
	j = 0;
	while (str[j] && j < n)
	{
		if (str[j] == to_find[0])
		{
			i = 1;
			while (to_find[i] && str[j + i] == to_find[i]
					&& (j + i) < n)
				i++;
			if (!to_find[i])
				return ((char *)&str[j]);
		}
		j++;
	}
	return (0);
}
