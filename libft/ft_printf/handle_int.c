/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:44:23 by sdiedra           #+#    #+#             */
/*   Updated: 2019/05/31 16:16:36 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

char	*ft_int_to_str(long long i, int precition)
{
	char	*str;
	int		len;

	if (i == 0 && precition == 0)
		return (ft_strnew(1));
	str = ft_llitoa(i);
	len = ft_strlen(str);
	if (*str == '-')
		--len;
	if (precition > len)
		str = ft_manage_pw(str, precition, len);
	return (str);
}

char	*ft_uint_to_str(unsigned long long i, t_specifier *spec)
{
	char	*str;
	int		len;

	if (i == 0 && spec->precition == 0)
		return (ft_strnew(1));
	if (spec->specifier == 'o' || spec->specifier == 'O')
		str = ft_ullitoa_base(i, "01234567", 8);
	else if (spec->specifier == 'x')
		str = ft_ullitoa_base(i, "0123456789abcdef", 16);
	else if (spec->specifier == 'X')
		str = ft_ullitoa_base(i, "0123456789ABCDEF", 16);
	else if (spec->specifier == 'b')
		str = ft_ullitoa_base(i, "01", 2);
	else
		str = ft_ullitoa_base(i, "0123456789", 10);
	len = ft_strlen(str);
	if (spec->precition > len)
		str = ft_manage_pw(str, spec->precition, len);
	else if (spec->precition < 0
			&& spec->width > len && spec->flags->zero && !spec->flags->cage)
		str = ft_manage_pw(str, spec->width, len);
	else if (spec->precition < 0
			&& spec->width > len && spec->flags->zero && spec->flags->cage)
		str = ft_manage_pw(str, spec->width - 2, len);
	return (str);
}
