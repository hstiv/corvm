//
// Created by hstiv on 03.07.19.
//

#include "corvm.h"

t_vm			*new_vm(void)
{
	t_vm		*vm;

	if (!(vm = (t_vm *)malloc(sizeof(t_vm))))
		exit(0);
	if (vm)
	{
		vm->nbr_cycles = 0;
		vm->champ_nb = 0;
	}
	return (vm);
}
