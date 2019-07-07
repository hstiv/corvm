//
// Created by hstiv on 03.07.19.
//

#include "corvm.h"

int					ft_isdigit_s(char *s)
{
	int				i;

	i = (s[0] == '-') ? 1 : 0;
	while (s[i])
	{
		if (!(s[i] >= 48 && s[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

int 				default_number(t_vm *vm)
{
	int 			*n;
	int 			i;

	n = vm->ints;
	i = 0;
	while (i < vm->champ_nb)
	{
		i++;
	}
	return (1);
}
