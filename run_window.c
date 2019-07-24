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

void				putarenainwindow(t_vm *vm)
{
	int				i;
	int				y;
	int				x;
	char			*s;

	i = 0;
	y = 10;
	while (i < MEM_SIZE)
	{
		x = 5;
		while ((i + 1) % BIT_LENTH != 0 && i < MEM_SIZE)
		{
			s = itoa_base(vm->arena[i + 1], STEEN, 16);
			ft_printf("\n%s   %p   %p   %d    %d    %d\n", s, vm->mlx->ptr, vm->mlx->wind, x, y, WHITE);
			ft_putstr("Error");
			mlx_string_put(vm->mlx->ptr, vm->mlx->wind, x, y, WHITE, s);
			ft_putstr("Error");
			x += 15;
			free(s);
			i++;
		}
		y += 20;
		i++;
	}
	i = 0;
	while (i < vm->champ_nb)
		draw_carriage(vm->mlx, &vm->champs[i++]);
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

//void				run_window(t_mlx *mlx)
//{
//	ft_putstr("corewar qaaaaaaaaaa");
//	mlx_hook(mlx->wind, 17, (1L << 17), expose_hook, mlx);
//	mlx_hook(mlx->wind, 2, 0, key_press, mlx);
//	putarenainwindow(mlx);
//}

//void				looper(t_mlx *mlx)
//{
//	usleep(mlx->mseconds);
//	run_window(mlx);
//	mlx_loop(mlx->ptr);
//}
