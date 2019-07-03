//
// Created by hstiv on 03.07.19.
//

#include "corvm"

int					ischamp(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '.')
		i++;
	if (s[i] == '\0')
		return (0);
	else if (ft_strequ(s + i + 1, "cor"))
		return (1);
	return (0);
}

int					is_dump_flag(char **s, t_vm *vm)
{
	if (!ft_strequ(s[1], "-dump"))
		return (1);
	else
	{
		if (!ft_isdigit(s[2]))
			return (-1);
		else
			vm->nbr_cycles = ft_atoi(s);
	}
	return ((vm->nbr_cycles < 0) ? -1 : 3);
}

int					champ_rec(char *s, t_vm *vm)
{
	int				fd;

	if (!(fd = open(s, "O_RDONLY")) || fd < 0)
		return (0);

}

int					is_nflag(char **s, int *i, t_vm *vm)
{
	if (!ft_strequ(s[*i], "-n"))
		return (0);
	else
	{
		*(i)++;
		if (!ft_isdigit(s[2]))
			return (0);
		else
		{
			vm->n_place = ft_atoi(s[*i]);
			*(i)++;
		}
	}
	if (vm->n_place < 0)
		return (0);
	return (1);
}

int					parser(int c, char **s, t_vm *vm)
{
	int				i;

	if ((i = is_dump_flag(s, vm)) == -1)
		threw(USAGE);
	while (i <= c)
	{
		if (ischamp(s[i]))
		{
			if (!champ_rec(s[i], vm))
				threw(USAGE);
		}
		else
		{
			if (!is_nflag(s, &i, vm))
				threw(USAGE);
		}
		i++;
	}
}
