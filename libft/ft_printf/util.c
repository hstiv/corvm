/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:46:19 by sdiedra           #+#    #+#             */
/*   Updated: 2019/05/31 16:16:48 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

int		is_valid_spec(t_specifier **sp, int *done)
{
	if (!*sp)
		handle_error(0, NULL);
	if (!(*sp)->specifier)
		return (0);
	if (!ft_strchr("dDioOuUxXscCpfFbrkge", (*sp)->specifier))
	{
		print_specifier(*sp, done);
		return (0);
	}
	return (1);
}

void	normalize_spec(t_specifier **spec)
{
	if (ft_strchr("dixX", (*spec)->specifier) && (*spec)->precition >= 0)
		(*spec)->flags->zero = 0;
	if ((*spec)->specifier == 'p' && (*spec)->flags->plus)
		(*spec)->flags->plus = 0;
	if ((*spec)->specifier == 'p' && (*spec)->flags->space)
		(*spec)->flags->space = 0;
}

int		is_flag(char c)
{
	if (ft_strchr("#-+ 0", c))
		return (1);
	return (0);
}

int		get_length_len(char *fmt)
{
	int	l_len;

	l_len = 0;
	if (ft_strchr("hlLzj", *fmt))
		l_len++;
	if ((*fmt == 'h' && *(fmt + 1) == 'h')
		|| (*fmt == 'l' && *(fmt + 1) == 'l'))
		l_len++;
	return (l_len);
}

void	spec_del(t_specifier **sp)
{
	if ((*sp)->length)
		free((*sp)->length);
	if ((*sp)->flags)
		free((*sp)->flags);
	free(*sp);
	*sp = NULL;
}
