/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:56:57 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/06 20:16:30 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *new;

	new = 0;
	if (!(new = malloc(sizeof(*new) * size)))
		return (0);
	while (size--)
		*(unsigned char*)(new + size) = 0;
	return (new);
}
