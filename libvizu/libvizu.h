/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvizu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:19:02 by mwuckert          #+#    #+#             */
/*   Updated: 2019/04/12 19:18:26 by mwuckert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVIZU_H
# define LIBVIZU_H

# define HEIGHT 1395
# define WIDTH 2560
# define LINE 20
# define COLOR 50
# define CON 5

# include <math.h>
# include "libft.h"
# include "corvm.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_mlx
{
	void			*wind;
	void			*ptr;
	void			*img;
	int 			mseconds;
	int 			memsize;
	int 			pause;
	void			*vm;
}					t_mlx;

void				add_end(char *s1, char *s, int n);
void				putarenainwindow(t_mlx *mlx);
void				dynamic_clear(char *s, int n);
char				*itoa_base(unsigned long long num,
								const char *sym, int base);
void				ft_sleep(int n);
void				looper(t_mlx *mlx);
void				init_mlx(t_mlx *mlx, t_vm *vm);
/*
**void				put_man(t_fdf *mlx);
*/
int					ft_close(void *param);
int					key_press(int keycode, t_mlx *param);
/*
**void				ft_bresenham(t_mlx *d0, t_mlx *d1, t_fdf *mlx);
*/
void				run_window(t_mlx *mlx);

#endif
