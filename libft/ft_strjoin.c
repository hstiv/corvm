/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:32:05 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/04 20:32:05 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	int		l;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(str = ft_strnew(i + j)))
		return (NULL);
	l = 0;
	while (s1[l])
	{
		str[l] = s1[l];
		l++;
	}
	k = -1;
	while (s2[++k])
	{
		str[l] = s2[k];
		l++;
	}
	return (str);
}
