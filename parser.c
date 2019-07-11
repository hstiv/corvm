//
// Created by hstiv on 03.07.19.
//

#include "corvm.h"

int					ischamp(char *s)
{
	char	*c;

	if ((c = ft_strstr(s, ".cor")) == NULL)
		return (0);
	if (ft_strlen(c) > 4 || ft_strlen(s) <= 4)
		return (0);
	return (1);
}

void				is_dump_flag(t_vm *vm, char **av, int c, int *i)
{
	if (!ft_strcmp("-dump", av[*i]))
	{
        if (*i + 1 < c && ft_isdigit_s(av[*i + 1]))
            vm->dump_cycles = ft_atoi(av[++(*i)]);
		else
			threw(USAGE);
    }
}

int					is_nflag(char **s, int *i)
{
	int 			n;

	n = 0;
	if (ft_strequ(s[*i], "-n"))
	{
		if (!s[++(*i)] || !ft_isdigit_s(s[*i]))
			return (0);
		else
			n = ft_atoi(s[(*i)]);
		if (n <= 0 || n > MAX_PLAYERS)
			return (0);
		if (!s[++(*i)])
			return (0);
	}
	return (n);
}

void				parser(int c, char **s, t_vm *vm)
{
	int				i;
	int				n;
	int				cc;
	int				j;

	i = 1;
	j = 1;
	while (i < c)
	{
		if (!ft_strcmp("-dump", s[i]))
			is_dump_flag(vm, s, c, &i);
		else if (ischamp(s[i]))
		{
			parse_champs(vm, s[i], vm->champ_nb, vm->next_champ_numb);
			vm->champs[vm->champ_nb].n_flag = 0;
			vm->champ_nb += 1;
			vm->next_champ_numb += 1;
		}
		else if ((n = is_nflag(s, &i)) != 0)
		{
			cc = 0;
			while (cc < vm->champ_nb)
			{
				if (vm->champs[cc].n_flag == 1 && n == vm->champs[cc].n_place)
					threw(USAGE);
				cc++;
			}
			if (n == vm->next_champ_numb)
				vm->next_champ_numb += 1;
			else if (n < vm->next_champ_numb)
			{
				cc = 0;
				while (cc < vm->next_champ_numb)
				{
					if (vm->champs[cc].n_flag == 1)
						j++;
					else
					{
						vm->champs[cc].n_place += j;
						j = 1;
					}
					cc++;
				}
				vm->next_champ_numb += 1;
			}
			parse_champs(vm, s[i], vm->champ_nb, n);
			vm->champs[vm->champ_nb].n_flag = 1;
			vm->champ_nb += 1;
		}
		else
			threw(USAGE);
		i++;
	}
}
