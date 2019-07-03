//
// Created by hstiv on 03.07.19.
//

#ifndef CORVM_H
# define CORVM_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

# define USAGE "> ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ..."

typedef struct		s_vm /* main vm's struct */
{
	int				nbr_cycles; /* [-dump] arg */
	int				n_place; /* -n arg */ /* todo */
	t_champ			champs[CHAMP_MAX_SIZE]; /* massive of champions */
}					t_vm;

typedef struct		s_champ /* champion's struct */
{
	char			*name; /* champions name */
	unsigned char	champ_bin; /* binary's byte code */
	int				champ_nb; /* champions nb */
}					t_champ;

int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strlen(char *s);
int					ft_atoi(char *s);
int					ft_isdigit(char *s);
int					parser(int c, char **s, t_vm *vm);
int					is_dump_flag(char **s, t_vm *vm)
int					ischamp(char *s);

#endif
