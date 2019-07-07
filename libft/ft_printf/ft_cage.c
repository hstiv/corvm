/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:39:41 by sdiedra           #+#    #+#             */
/*   Updated: 2019/05/31 16:15:06 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_cage_x(size_t slen, char *str)
{
	char	*new;

	if (!(new = ft_strnew(slen + 2)))
		return (NULL);
	new[0] = '0';
	new[1] = 'x';
	ft_strlcat(new + 2, str, slen + 1);
	free(str);
	return (new);
}

char	*ft_cage_bigx(size_t slen, char *str)
{
	char	*new;

	if (!(new = ft_strnew(slen + 2)))
		return (NULL);
	new[0] = '0';
	new[1] = 'X';
	ft_strlcat(new + 2, str, slen + 1);
	free(str);
	return (new);
}

char	*ft_cage_o(size_t slen, char *str)
{
	char	*new;

	if (!(new = ft_strnew(slen + 1)))
		return (NULL);
	new[0] = '0';
	ft_strlcat(new + 1, str, slen + 1);
	free(str);
	return (new);
}
