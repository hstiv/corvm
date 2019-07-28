#include "corvm.h"

void	op_lldi(t_vm *vm, t_proc *proc)
{
	int		type;
	int		i;
	int		j;
	int		args[3];

	i = -1;
	j = 0;
	while (++i < 2)
	{
		type = get_arg(vm->arena[(proc->pos + 1) % MEM_SIZE], 2, 7 - 2 * i);
		if (type == T_REG)
			args[i] = proc->reg[vm->arena[(proc->pos + 2 + j) % MEM_SIZE] - 1];
		else if (type == T_DIR)
			args[i] = rev_byte(vm, (proc->pos + 2 + j) % MEM_SIZE, 2);
		else
		{
			args[i] = rev_byte(vm, (proc->pos + 2 + j) % MEM_SIZE, 2) % IDX_MOD;
			args[i] = plus_pos(args[i], proc->pos);
			args[i] = rev_byte(vm, args[i], 4);
		}
		if (type == T_REG)
			j += 1;
		else
			j += 2;
	}
	args[2] = vm->arena[(proc->pos + 2 + j) % MEM_SIZE] - 1;
	if ((i = rev_byte(vm,
					  (proc->pos + (args[0] + args[1])) % MEM_SIZE, 4)) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->reg[args[2]] = i;
}

void	op_lfork(t_vm *vm, t_proc *proc)
{
	int arg;
	int	i;

	i = -1;
	arg = rev_byte(vm, (proc->pos + 1) % MEM_SIZE, 2);
	arg = plus_pos(arg, proc->pos);
	proccess_add(&vm->list_process, new_proc(vm->list_process->player_id, arg));
	vm->list_process->carry = proc->carry;
	vm->list_process->live = proc->live;
	while (++i < REG_NUMBER)
		vm->list_process->reg[i] = proc->reg[i];
	proc->pos = (proc->pos + 3) % MEM_SIZE;
}

void	op_aff(t_vm *vm, t_proc *proc)
{
	int		i;

	i = vm->arena[(proc->pos + 2) % MEM_SIZE] - 1;
	ft_printf("%c\n", (char)proc->reg[i]);
}

int		plus_pos(int i, int j)
{
	if (i + j < 0)
	{
		if ((i + j) % MEM_SIZE)
			return ((MEM_SIZE + (i + j) % MEM_SIZE));
		else
			return (0);
	}
	else
		return ((i + j) % MEM_SIZE);
}
