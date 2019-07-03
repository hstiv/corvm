//
// Created by hstiv on 03.07.19.
//

#include "corvm.h"

t_vm			*new_vm(void)
{
	t_vm		*vm;

	if (!(vm = (t_vm *)malloc(sizeof(t_vm))))
		threw("Error");
	if (vm)
	{
		vm->nbr_cycles = 0;
		vm->n_place = 0;
	}
	return (vm);
}

t_champ			*new_champ(void)
{
	t_champ		*new;

	if (!(new = (t_champ *)malloc(sizeof(t_champ))))
		threw("Error");
	if (new)
	{
		new->champ_nb = 0;
		new->name = 0;
		new->champ_bin = NULL;
	}
	return (new);
}
