/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:08:55 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/04 18:44:19 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*str1;
	char	*to_find1;
	char	*s1;
	char	*s2;

	str1 = (char *)str;
	to_find1 = (char *)to_find;
	if (*to_find1 == '\0')
		return (str1);
	while (*str1)
	{
		s1 = str1;
		s2 = to_find1;
		while (*str1 && *s2 && *str1 == *s2)
		{
			str1++;
			s2++;
		}
		if (!*s2)
			return (s1);
		str1 = s1 + 1;
	}
	return (NULL);
}
