/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corvm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:27:47 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/16 16:36:37 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORVM_H
# define CORVM_H

# include <string.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "op.h"
# include "mlx.h"
# include <math.h>

# include "../libft/libft.h"

# define BUFF_SIZE	32
# define MAX_FD		10240
# define USAGE		"Usage: ./corvm [-dump nbr_cycles] [[-n number] champion1.cor] ...\n"
# define HEIGHT		1395
# define WIDTH		2560
# define LINE		20
# define COLOR		50
# define CON		5
# define STEEN 		"0123456789abcdef"
# define UL			unsigned long int
# define WHITE		16777215
# define GREEN		46080
# define BIT_LENTH	32

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

typedef struct		s_proc
{
	int				carry;
	unsigned int	reg[REG_NUMBER];
	int				pos;
	int				player_id;
	int				cycles_to_wait;
	int				live;
	int				command_type;
	struct s_proc	*next;
}					t_proc;


typedef struct		s_champ
{
	unsigned char	name[PROG_NAME_LENGTH + 1]; 
	unsigned char	champ_bin[CHAMP_MAX_SIZE];
	unsigned char	comment[COMMENT_LENGTH + 1];
	int				magic;
	int				n_flag;
	int				n_place;
	int				exec_code;
	int				pos;
	int				live;
	int				lives_in_period;
}					t_champ;

typedef struct		s_vm
{
	int				dump_cycles;
	int				champ_nb;
	t_champ			champs[MAX_PLAYERS];
	t_proc			*list_process;
	unsigned char	arena[MEM_SIZE];
	unsigned char	owner[MEM_SIZE];
	int				next_champ_numb;
	int				cycles;
	int				cycles_to_die;
	int				cycles_die;
	int				winner;
	int				winner_n;
	int				checks;
	int				l_exec;
	t_mlx			*mlx;
}					t_vm;

typedef struct			s_op
{
	char				*name;
	int					number;
	unsigned char		types_arg[3];
	int					opcode;
	int					cycles_wait;
	char				*description;
	int					coding_byte;
	int					is_short_dir;
}						t_op;

void				eat_vizu(int *i, t_vm *vm);
int 				cor_sort(t_vm *vm);
void				init_op(t_op op_tab[17]);
void				show_dump(t_vm *vm);
void				play_game(t_vm *vm, t_op op_tab[17]);
void				arena(t_vm *vm);
int					ft_isdigit_s(char *s);
void				parser(int c, char **s, t_vm *vm);
void				threw(char *s);
void				parse_champs(t_vm *vm, char *name, int n, int number);
void				new_vm(t_vm *vm);
int 				default_number(t_vm *vm);

void				op_live(t_vm *vm, t_proc *proc);
void				op_ld(t_vm *vm, t_proc *proc);
void				op_st(t_vm *vm, t_proc *proc);
void				op_add(t_vm *vm, t_proc *proc);
void				op_sub(t_vm *vm, t_proc *proc);
void				op_and(t_vm *vm, t_proc *proc);
void				op_or(t_vm *vm, t_proc *proc);
void				op_xor(t_vm *vm, t_proc *proc);
void				op_zjmp(t_vm *vm, t_proc *proc);
void				op_ldi(t_vm *vm, t_proc *proc);
void				op_sti(t_vm *vm, t_proc *proc);
void				op_fork(t_vm *vm, t_proc *proc);
void				op_lld(t_vm *vm, t_proc *proc);
void				op_lldi(t_vm *vm, t_proc *proc);
void				op_lfork(t_vm *vm, t_proc *proc);
void				op_aff(t_vm *vm, t_proc *proc);
int					get_arg(int octet, int k, int p);
void				proccess_add(t_proc **head, t_proc *new_p);
t_proc				*new_proc(int player_id, int pos);


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