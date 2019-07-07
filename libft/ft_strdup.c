/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 22:02:24 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/18 14:52:31 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s2;
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(src);
	if (!(s2 = ft_strnew(n)))
		return (NULL);
	while (src[i] && i < n)
	{
		s2[i] = src[i];
		i++;
	}
	return (s2);
}
