/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_str_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:43:00 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/05 19:22:35 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_concat_str_arr(int argc, char **argv)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	i = 1;
	j = 1;
	len = 0;
	while (argc > 1)
	{
		len += ft_strlen(argv[i]);
		argc--;
		i++;
	}
	len += i;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (j < i)
	{
		str = ft_strcat(str, argv[j]);
		str = ft_strcat(str, "\n");
		j++;
	}
	return (str);
}
