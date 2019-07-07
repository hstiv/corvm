/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:41:22 by sdiedra           #+#    #+#             */
/*   Updated: 2019/05/31 16:14:18 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_make_str(t_specifier *spec)
{
	char	*str;

	if (spec->width && !spec->flags->zero)
		str = ft_fillstr(spec->width, ' ');
	else if (spec->width && spec->flags->zero)
		str = ft_fillstr(spec->width, '0');
	else
		str = ft_strnew(1);
	return (str);
}
