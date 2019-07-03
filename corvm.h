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

# define USAGE "Usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n"

# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)

typedef struct		s_champ /* champion's struct */
{
	unsigned char	name[PROG_NAME_LENGTH + 1]; /* champions name */
	unsigned char	champ_bin[CHAMP_MAX_SIZE]; /* binary's byte code */
	int				n_place; /* number of champ*/
}					t_champ;


typedef struct		s_vm /* main vm's struct */
{
	int				nbr_cycles; /* [-dump] arg лучше будет по другому назвать*/
	int				champ_nb; /* amount of champs */
	t_champ			champs[MAX_PLAYERS]; /* massive of champions */
}					t_vm;


int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strlen(char *s);
int					ft_atoi(const char *s);
int					ft_isdigit(char *s);
int					parser(int c, char **s, t_vm *vm);
int					is_dump_flag(char **s, t_vm *vm);
int					ischamp(char *s);

#endif
