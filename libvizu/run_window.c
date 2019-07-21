/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:11:41 by mwuckert          #+#    #+#             */
/*   Updated: 2019/04/12 19:25:15 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvizu.h"

void				add_end(char *s1, char *s, int n)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	s[i++] = 32;
	while (s1[j] != '\0')
	{
		s[i] = s1[j];
		i++;
		j++;
	}
	(n) ? free(s1) : 0;
}

void				putarenainwindow(t_mlx *mlx)
{
	int				i;
	int				y;
	char			s[128];
	t_vm			*vm;

	i = 0;
	y = 10;
	vm = (t_vm *)mlx->vm;
	while (i < 128)
		s[i++] = 0;
	i = 0;
	while (i < mlx->memsize)
	{
		dynamic_clear(s, 128);
		while ((i + 1) % 32 != 0 && i)
		{
			add_end(itoa_base(vm->arena[i], "0123456789abcdef", 16), s, 1);
			i++;
		}
		mlx_string_put(mlx->ptr, mlx->wind, 5, y, 65535, s);
		y += 20;
		i++;
	}
}

void				ft_sleep(int n)
{
	long long int	n1;
	int				n2;

	n2 = n;
	while (n2 != 0)
	{
		n1 = (n > 1 && n <= 5) ? 100000 : 0;
		if (n > 5)
			n1 = 1000000000;
		while (n1 != 0)
			n1--;
		n2--;
	}
}

void				run_window(t_mlx *mlx)
{
	mlx_hook(mlx->wind, 17, (1L << 17), ft_close, mlx);
	mlx_hook(mlx->wind, 2, 0, key_press, mlx);
	putarenaanwindow(mlx);
}

void				looper(t_mlx *mlx)
{
	ft_sleep(mlx->mseconds);
	run_window(mlx);
	mlx_loop(mlx->ptr);
}
