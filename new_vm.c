//
// Created by hstiv on 03.07.19.
//

#include "corvm.h"

void			new_vm(t_vm *vm)
{
	ft_memset(vm->arena, 0, MEM_SIZE);
	vm->next_champ_numb = 1;
	vm->dump_cycles = -1;
	vm->champ_nb = 0;
	vm->winner = 0;
	vm->cycles = 0;
}
