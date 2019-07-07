/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:40:50 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/22 17:46:07 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*join_lines(char *tmp, char *str, int size)
{
	char	*tmp2;
	char	*tmp3;

	if (!(tmp2 = (char *)malloc(sizeof(char) * size + 1)))
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	tmp2[size] = '\0';
	tmp2 = ft_strncpy(tmp2, str, size);
	if (!(tmp3 = ft_strjoin(tmp, tmp2)))
	{
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
		return (NULL);
	}
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	tmp = tmp3;
	return (tmp);
}
