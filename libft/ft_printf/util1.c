/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:46:53 by sdiedra           #+#    #+#             */
/*   Updated: 2019/05/31 16:16:51 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

void	flag_undefined(char flag, char spec)
{
	ft_putstr("warning: flag '");
	ft_putchar(flag);
	ft_putstr("' results in undefined behavior with '");
	ft_putchar(spec);
	ft_putstr("'\n");
}

void	handle_error(int code, t_specifier **sp)
{
	if (code == 0)
	{
		ft_putstr("");
		if (sp)
			spec_del(sp);
		exit(0);
	}
	else if (code == 1)
	{
		ft_putstr("warning: invalid conversion specifier '");
		ft_putchar((*sp)->specifier);
		ft_putstr("'\n");
	}
	else if (code == 2 || code == 3)
		flag_undefined(code == 2 ? '#' : '0', (*sp)->specifier);
	else if (code == 4)
		ft_putstr("warning: flag '0' is ignored when flag '-' is present\n");
	else if (code == 5)
		ft_putstr("warning: flag ' ' is ignored when flag '+' is present\n");
}
