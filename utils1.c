//
// Created by Hallie Stiv on 2019-07-27.
//

#include "corvm.h"

char 			*get_str(char *s, char *s1)
{
	char 		*s2;

	s2 = ft_strjoin(s, s1);
	free(s1);
	return (s2);
}

int 			lstcnt(t_proc *lst)
{
	int 		i;
	t_proc		*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char 				*get_name(t_vm *vm, int i)
{
	int 			t;
	char 			*s;
	char 			*s1;

	t = 0;
	s = (char *)malloc(sizeof(char) * 129);
	while (vm->champs[i].name[t] != '\0')
	{
		s[t] = (char) vm->champs[i].name[t];
		t++;
	}
	s[t] = '\0';
	s1 = ft_strjoin(vm->mlx->ply_man[i], s);
	return (s1);
}

void				put_players(int x, int y, t_vm *vm)
{
	int 			i;
	char 			*s;

	i = 0;
	while (i < vm->champ_nb)
	{
		y += 50;
		s = get_name(vm, i);
		mlx_string_put(vm->mlx->ptr, vm->mlx->wind, x, y, vm->colors[i], s);
		free(s);
		s = get_str(LL, ft_itoa(vm->champs[i].live));
		y += 20;
		mlx_string_put(vm->mlx->ptr, vm->mlx->wind, x + 30, y, WHITE, s);
		free(s);
		s = get_str(LICP, ft_itoa(vm->champs[i].lives_in_period));
		y += 20;
		mlx_string_put(vm->mlx->ptr, vm->mlx->wind, x + 30, y, WHITE, s);
		i++;
	}
}
