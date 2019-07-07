/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:06 by sdiedra           #+#    #+#             */
/*   Updated: 2019/05/31 16:15:35 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	dispatch_specifier(char **fmt, int *counter, va_list *ap)
{
	t_specifier	*sp;

	(*fmt)++;
	if (**fmt && **fmt == '%')
	{
		ft_putchar('%');
		(*fmt)++;
		(*counter)++;
		return ;
	}
	if (!**fmt)
		return ;
	sp = create_specifier(fmt);
	if (!is_valid_spec(&sp, counter))
	{
		spec_del(&sp);
		return ;
	}
	ft_dispatch_spec(sp, ap, counter);
}

int		ft_printf1(va_list *list, char *format)
{
	int		counter;

	if (!format)
		return (-1);
	counter = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			format++;
			counter++;
		}
		else
			dispatch_specifier(&format, &counter, list);
	}
	return (counter);
}

int		ft_printf(char *format, ...)
{
	va_list		list;
	int			print;

	va_start(list, format);
	print = ft_printf1(&list, format);
	va_end(list);
	return (print);
}
