//
// Created by Hallie Stiv on 2019-07-12.
//

#include "includes/corvm.h"

static void			swap_champs(t_champ *c1, t_champ *c2)
{
	t_champ			tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

int 				cor_sort(t_vm *vm)
{
	int 			i;
	int 			j;

	i = 0;
	while (i < vm->champ_nb)
	{
		j = i + 1;
		while (j < vm->champ_nb)
		{
			if (vm->champs[i].n_place > vm->champs[j].n_place)
				swap_champs(&vm->champs[i], &vm->champs[j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < vm->champ_nb)
	{
		if (vm->champs[i].n_place - 1 != i)
			return (0);
		i++;
	}
	return (1);
}
