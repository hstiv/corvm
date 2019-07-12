/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:05:38 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/02 21:30:20 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	while (str[k])
	{
		i++;
		k++;
	}
	return (i);
}