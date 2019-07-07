/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:05:13 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/04 20:28:29 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while ((s[i] == '\n' || s[i] == ' ' || s[i] == '\t') && i < j)
		i++;
	while ((s[j - 1] == '\n' || s[j - 1] == ' ' || s[j - 1] == '\t') && i < j)
		j--;
	if (!(str = ft_strnew(j - i)))
		return (NULL);
	k = 0;
	while (i < j)
	{
		str[k] = s[i];
		i++;
		k++;
	}
	return (str);
}
