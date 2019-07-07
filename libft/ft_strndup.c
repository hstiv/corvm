/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:28:25 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/23 16:32:29 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strndup(const char *src, size_t size)
{
	char	*s2;
	size_t	i;
	size_t	n;

	i = 0;
	if (ft_strlen(src) < size)
		n = ft_strlen(src);
	else
		n = size;
	if (!(s2 = ft_strnew(n)))
		return (NULL);
	while (src[i] && i < n)
	{
		s2[i] = src[i];
		i++;
	}
	return (s2);
}
