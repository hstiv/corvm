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

#include "corvm.h"

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
	s[i] = '\0';
	(n) ? free(s1) : 0;
}

void				putarenainwindow(t_vm *vm, t_mlx *mlx)
{
	int				i;
	int				y;
	int				x;
	char			*s;

	i = 0;
	y = 10;
	while (i < MEM_SIZE)
	{
		x = 10;
		while ((i + 1) % BIT_LENTH != 0 && i < MEM_SIZE)
		{
			s = itoa_base(vm->arena[i], 16);
			mlx_string_put(mlx->ptr, mlx->wind, x, y, WHITE, s);
			x += 15;
			free(s);
			i++;
		}
		y += 20;
		i++;
	}
	i = 0;
	while (i < vm->champ_nb)
		draw_carriage(mlx, &vm->champs[i++]);
}

//void				ft_sleep(int n)
//{
//	long long int	n1;
//	int				n2;
//
//	n2 = n;
//	while (n2 != 0)
//	{
//		n1 = (n > 1 && n <= 5) ? 100000 : 0;
//		if (n > 5)
//			n1 = 1000000000;
//		while (n1 != 0)
//			n1--;
//		n2--;
//	}
//}
