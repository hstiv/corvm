/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:45:35 by sdiedra           #+#    #+#             */
/*   Updated: 2019/05/31 16:16:43 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

char	*ft_make_pointer(t_specifier *spec, va_list *ap)
{
	char				*address;
	char				*tmp;
	unsigned long int	p;
	int					len;

	(void)spec;
	if (spec->precition == 0)
	{
		address = ft_strjoin("0x", "\0");
		return (address);
	}
	p = (unsigned long int)va_arg(*ap, void *);
	tmp = ft_ullitoa_base(p, "0123456789abcdef", 16);
	if (!tmp)
		return (NULL);
	len = (int)ft_strlen(tmp);
	if (spec->precition > len)
		tmp = ft_manage_pw(tmp, spec->precition, len);
	address = ft_strjoin("0x", tmp);
	free(tmp);
	if (!address)
		return (NULL);
	return (address);
}
