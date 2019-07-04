/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corvm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:27:47 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/04 16:11:01 by sdiedra          ###   ########.fr       */
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

# define BUFF_SIZE	32
# define MAX_FD		10240
# define UL			unsigned long int
# define USAGE		"Usage: ./corvm [-dump nbr_cycles] [[-n number] champion1.cor] ...\n"

typedef struct		s_proc
{
	int				carry;
	int				reg[REG_NUMBER];
	int				pos;
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
}					t_champ;

typedef struct		s_vm /* main vm's struct */
{
	int				dump_cycles; /* [-dump] arg */
	int				champ_nb; /* -n arg */ /* todo */
	t_champ			champs[MAX_PLAYERS]; /* massive of champions */
	int 			ints[MAX_PLAYERS];
	t_proc			*list_process;
	int 			flag;
	int 			nextInMassiv;
	int 			next_champ_nb;
}					t_vm;

void				*ft_memset(void *b, int c, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memmove(void *dest, const void *source, size_t len);
void				*ft_memcpy(void *dest, const void *source, size_t n);
char				*ft_strnew(size_t size);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strlen(char *s);
int					ft_atoi(const char *s);
int					ft_isdigit(char *s);
int					is_nflag(char **s, int *i, int *t, t_vm *vm);
void				parser(int c, char **s, t_vm *vm);
int					is_dump_flag(char **s, int *i, t_vm *vm, int *t);
int					ischamp(char *s, int *t);
void				threw(char *s);
void				parse_champs(t_vm *vm, char *name, int n, int number);
void				new_vm(t_vm *vm);

#endif
