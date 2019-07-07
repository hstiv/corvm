/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:49:07 by sdiedra           #+#    #+#             */
/*   Updated: 2019/05/31 16:14:55 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_upper_dispatch_uint(t_specifier *spec, va_list *ap)
{
	char	*str;

	str = ft_uint_to_str(va_arg(*ap, unsigned long), spec);
	return (str);
}

char	*ft_upper_dispatch_int(t_specifier *spec, va_list *ap)
{
	char	*str;

	str = ft_int_to_str(va_arg(*ap, long), spec->precition);
	return (str);
}
