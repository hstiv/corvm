#include "corvm.h"

void    arena(t_vm *vm)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (i < vm->champ_nb)
    {
        ft_memcpy(&(vm->arena[n]), vm->champs[i].champ_bin, vm->champs[i].exec_code);
        vm->champs[i].pos = n;
        n += MEM_SIZE / vm->champ_nb;
        i++;
    }
}
