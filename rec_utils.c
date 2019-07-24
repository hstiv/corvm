//
// Created by hstiv on 03.07.19.
//

#include "includes/corvm.h"

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
