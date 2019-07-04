//
// Created by hstiv on 03.07.19.
//

#include "corvm.h"

void		threw(char *s)
{
	write(1, s, ft_strlen(s));
	exit(0);
}

int			main(int c, char **s)
{
	t_vm	vm;

	new_vm(&vm);
	if (c == 1)
		threw(USAGE);
	parser(c, s, &vm);
}
