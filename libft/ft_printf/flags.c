/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:43:12 by sdiedra           #+#    #+#             */
/*   Updated: 2019/05/31 16:14:59 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

char		*ft_resolve_plus(char *str)
{
	char	*new;
	size_t	slen;

	slen = ft_strlen(str);
	if (ft_isdigit(*str))
	{
		if (!(new = ft_strnew(slen + 1)))
			return (NULL);
		new[0] = '+';
		ft_strlcat(new + 1, str, slen + 1);
		free(str);
		return (new);
	}
	return (str);
}

char		*ft_resolve_cage(char *str, t_specifier *spec)
{
	size_t	slen;

	slen = ft_strlen(str);
	if (spec->specifier == 'x' && ft_strcmp("0", str) && ft_strcmp("", str))
		return (ft_cage_x(slen, str));
	else if (spec->specifier == 'X'
			&& ft_strcmp("0", str) && ft_strcmp("", str))
		return (ft_cage_bigx(slen, str));
	else if ((spec->specifier == 'o' || spec->specifier == 'O') && *str != '0')
		return (ft_cage_o(slen, str));
	return (str);
}

char		*ft_resolve_space(char *str)
{
	char	*new;
	size_t	slen;

	slen = ft_strlen(str);
	if (ft_isdigit(*str))
	{
		if (!(new = ft_strnew(slen + 1)))
			return (NULL);
		new[0] = ' ';
		ft_strlcat(new + 1, str, slen + 1);
		free(str);
		return (new);
	}
	return (str);
}

char		*ft_resolve_width(char *str, t_specifier *spec, int width)
{
	char	*new;
	int		slen;

	slen = ft_strlen(str);
	new = str;
	if (spec->flags->zero && slen < width)
		new = ft_str_add_zeros(str, width - slen, spec);
	else if (spec->flags->minus && slen < width)
		new = ft_str_add_spaces(str, width - slen);
	else
		new = ft_str_add_left_spaces(str, width - slen);
	return (new);
}

char		*ft_manage_flags(char *str, t_specifier *spec)
{
	char	*new_str;

	new_str = str;
	if (spec->flags->plus && ft_strchr("dife", spec->specifier))
		new_str = ft_resolve_plus(str);
	else if (spec->flags->cage && ft_strchr("xXoO", spec->specifier))
		new_str = ft_resolve_cage(str, spec);
	else if (spec->flags->space && ft_strchr("di", spec->specifier))
		new_str = ft_resolve_space(str);
	if ((int)ft_strlen(new_str) < spec->width && spec->specifier != 'c')
		new_str = ft_resolve_width(new_str, spec, spec->width);
	return (new_str);
}
