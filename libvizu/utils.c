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

#include "libvizu.h"

void			dynamic_clear(char *s, int n)
{
	int			i;

	i = 0;
	while (i < n)
		s[i++] = '\0';
}

static int		ft_num_len(unsigned long long n, int base)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= base;
		len += 1;
	}
	return (len);
}

char			*itoa_base(unsigned long long num,
								const char *sym, int base)
{
	char	*str;
	int		len;

	len = ft_num_len(num, base);
	if (num == 0)
		len = 1;
	if ((str = ft_strnew((size_t)len)) == NULL)
		return (NULL);
	while (len - 1 >= 0)
	{
		str[len - 1] = sym[num % base];
		num /= base;
		len--;
	}
	return (str);
}

void			get_x_y(t_dot *n1, t_champ *champ)
{
	int 		tmp;

	n1->x = 0;
	n1->y = 0;
	tmp = champ->pos;
	while (tmp >= 64)
	{
		tmp -= 64;
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
