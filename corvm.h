/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corvm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:27:47 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/12 18:36:53 by sdiedra          ###   ########.fr       */
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
# include "libft/libft.h"

# define BUFF_SIZE	32
# define MAX_FD		10240
# define UL			unsigned long int
# define USAGE		"Usage: ./corvm [-dump nbr_cycles] [[-n number] champion1.cor] ...\n"

typedef struct		s_proc
{
	int				carry;
	unsigned int	reg[REG_NUMBER];
	int				pos;
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
	int				winner;
	unsigned char	winner_name[PROG_NAME_LENGTH + 1]; 
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

#endif
