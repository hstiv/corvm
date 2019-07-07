/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:35:18 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/04 21:10:33 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		dstlength;
	size_t		srclength;

	i = 0;
	dstlength = ft_strlen(dest);
	srclength = ft_strlen(src);
	if (size <= dstlength)
		return (srclength + size);
	while (dest[i] && i < (size - 1))
		i++;
	while (*src && i < (size - 1))
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dstlength + srclength);
}
