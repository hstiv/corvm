/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwuckert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:47:18 by mwuckert          #+#    #+#             */
/*   Updated: 2018/12/07 20:52:00 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s || !(sub = (char*)(ft_memalloc(sizeof(*s) * len + 1))))
		return (0);
	ft_strncpy(sub, s + start, len);
	*(sub + len + 1) = '\0';
	return (sub);
}
