//
// Created by hstiv on 03.07.19.
//

#include "corvm.h"

int					ischamp(char *s, int *t)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '.')
		i++;
	if (s[i] == '\0')
		return (0);
	else if (ft_strequ(s + i + 1, "cor") && i != 0)
	{
		(*t)++;
		return (1);
	}
	return (0);
}

int					is_dump_flag(char **s, int *i, t_vm *vm, int *t)
{
	if (ft_strequ(s[*i], "-dump"))
	{
		if (!s[++(*i)] || !ft_isdigit(s[*i]))
			return (0);
		else
			vm->dump_cycles = ft_atoi(s[*i]);
		if (vm->dump_cycles < 0)
			return (0);
		(*t)++;
		(*i)++;
	}
	return (1);
}

int					champ_rec(char *s, t_vm *vm)
{
	int 			i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (vm->ints[i] == vm->next_champ_nb && vm->ints[i] != 0)
			threw("Error: Wrong args of flag [-n]\n");
		i++;
	}
	parse_champs(vm, s, vm->nextInMassiv, vm->next_champ_nb);
	vm->champ_nb++;
	vm->flag--;
	return (1);
}

int					is_nflag(char **s, int *i, int *t, t_vm *vm)
{
	int 			n;

	n = 0;
	if (ft_strequ(s[*i], "-n"))
	{
		(*i)++;
		if (!ft_isdigit(s[*i]))
			return (0);
		else
			n = ft_atoi(s[(*i)++]);
		if (n < 0 || n > CHAMP_MAX_SIZE)
			return (0);
		(*t)++;
		vm->flag++;
	}
	vm->next_champ_nb = n;
	return (1);
}

int					parser(int c, char **s, t_vm *vm)
{
	int				i;
	int 			t;

	i = 1;
	while (i < c)
	{
		t = 0;
		if (!is_dump_flag(s, &i, vm, &t))
			threw("Usage: [-dump [number > 0]] champion.cor\n");
		else if (t == 0 && ischamp(s[i], &t))
		{
			if (!champ_rec(s[i++], vm))
				threw("Non valid champion\n");
		}
		else if (t == 0 && !is_nflag(s, &i, &t, vm))
				threw("Usage: [-n [number > 0]] champion.cor\n");
		else if (t == 0)
				threw(USAGE);
	}
	if (vm->champ_nb == 0 || vm->flag > 0)
		threw(USAGE);
	if (!defaultNumbering(vm))
		threw("Error: Wrong args of flag [-n]\n");
	return (1);
}
