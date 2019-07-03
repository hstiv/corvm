//
// Created by hstiv on 03.07.19.
//

#ifndef CORVM_H
# define CORVM_H

# include <string.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE	32
# define MAX_FD		10240
# define UL			unsigned long int
# define USAGE "> ./corvm [-dump nbr_cycles] [[-n number] champion1.cor] ..."
# define CHAMP_MAX_SIZE 4

typedef struct		s_champ /* champion's struct */
{
	char			*name; /* champions name */
	unsigned char	*champ_bin; /* binary's byte code */
	int				champ_nb; /* champions nb */
}					t_champ;

typedef struct		s_vm /* main vm's struct */
{
	int				nbr_cycles; /* [-dump] arg */
	int				n_place; /* -n arg */ /* todo */
	t_champ			*champs[CHAMP_MAX_SIZE]; /* massive of champions */
}					t_vm;

int 				get_next_line(int fd, char **line);
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
int					parser(int c, char **s, t_vm *vm);
int					is_dump_flag(char **s, t_vm *vm);
int					ischamp(char *s);
void				threw(char *s);
int 				vm_number(t_vm *vm);
void				unsign_joiner(t_champ *champ, char *line);
t_vm				*new_vm(void);
t_champ				*new_champ(void);

#endif
