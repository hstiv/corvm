#include "corvm.h"

void		proccess_init_reg(unsigned int *reg)
{
	int	i;

	i = 0;
	while (i < REG_NUMBER)
	{
		reg[i] = 0;
		i++;
	}
}

t_proc	*new_proc(int player_id, int pos)
{
	t_proc	*new_pr;

	new_pr = (t_proc *)malloc(sizeof(t_proc));
	if (!new_pr)
		return (NULL);
	proccess_init_reg(new_pr->reg);
	new_pr->reg[0] = -player_id;
    new_pr->carry = 0;
    new_pr->pos = pos;
	return (new_pr);
}

void		proccess_add(t_proc **head, t_proc *new_p)
{
	if (head && new_p)
	{
		new_p->next = *head;
		*head = new_p;
	}
}

void    init_proc(t_vm *vm)
{
    int i;

    i = vm->champ_nb;
    while (i > 0)
    {
        proccess_add(&vm->list_process, new_proc(i, vm->champs[i].pos));
        i--;
    }
}

void    arena(t_vm *vm)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (i < vm->champ_nb)
    {
        ft_memcpy(&(vm->arena[n]), vm->champs[i].champ_bin, vm->champs[i].exec_code);
        ft_memset(&(vm->owner[n]), i + 1, vm->champs[i].exec_code);
        vm->champs[i].pos = n;
        n += MEM_SIZE / vm->champ_nb;
        i++;
    }
    init_proc(vm);
}
