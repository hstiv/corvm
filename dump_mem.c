#include "corvm.h"

void	show_dump(t_vm *vm)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%02hhx ", vm->arena[i]);
		if ((i + 1) % 32 == 0 && i)
			ft_printf("\n");
		i++;
	}
	ft_printf("\n");
	exit(0);
}
