/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:55:58 by hstiv             #+#    #+#             */
/*   Updated: 2019/07/21 17:56:05 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.h"

void			dynamic_clear(char *s, int n)
{
	int			i;

	i = 0;
	while (i < n)
		s[i++] = '\0';
}

char			*itoa_base(int value, int base)
{
	char	*s;
	long	n;
	int		sign;
	int		i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

void			get_x_y(t_dot *n1, t_champ *champ)
{
	int 		tmp;

	n1->x = 0;
	n1->y = 0;
	tmp = champ->pos;
	while (tmp >= BIT_LENTH)
	{
		tmp -= BIT_LENTH;
		n1->x++;
	}
	n1->y = tmp * 15 + 5;
}

void			draw_carriage(t_mlx *mlx, t_champ *champ)
{
	t_dot		n1;
	t_dot		n2;
	int 		i;

	i = 0;
	get_x_y(&n1,champ);
	n2.x = n1.x;
	n2.y = n1.y + 1;
	while (i < 5)
	{
		ft_bresenham(&n1, &n2, mlx, GREEN);
		n1.x++;
		n2.x++;
		i++;
	}
}
