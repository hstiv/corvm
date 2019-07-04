//
// Created by hstiv on 03.07.19.
//

#include "corvm.h"

void			new_vm(t_vm *vm)
{
	int 		i;

	i = 0;
	while (i < MAX_PLAYERS)
		vm->ints[i++] = 0;
	vm->dump_cycles = 0;
	vm->champ_nb = 0;
	vm->flag = 0;
	vm->next_champ_nb = 0;
	vm->nextInMassiv = 0;
}
