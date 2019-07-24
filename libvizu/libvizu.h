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

# include <math.h>
# include "libft.h"
# include "corvm.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define HEIGHT		1395
# define WIDTH		2560
# define LINE		20
# define COLOR		50
# define CON		5
# define STEEN 		"0123456789abcdef"
# define UL			unsigned long int
# define WHITE		16777215
# define GREEN		46080

typedef struct		s_dot
{
	int 			x;
	int 			y;
}					t_dot;

typedef struct		s_mlx
{
	void			*wind;
	void			*ptr;
	void			*img;
	int 			mseconds;
	int 			memsize;
	int 			pause;
	int 			err;
	int 			derr;
	void			*vm;
}					t_mlx;

void				get_x_y(t_dot *n1, t_champ *champ);
void				ft_bresenham(t_dot *d0, t_dot *d1,
										t_mlx *mlx, int color);
void				draw_carriage(t_mlx *mlx, t_champ *champ);
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
