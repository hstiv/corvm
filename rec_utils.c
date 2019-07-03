//
// Created by hstiv on 03.07.19.
//

#include "corvm.h"

int 				vm_number(t_vm *vm)
{
	int 			i;

	i = 0;
	while (vm->champs[i] != NULL)
		i++;
	return (i);
}

void				unsign_joiner(t_champ *champ, char *line)
{
	int 			i;
	unsigned char	*bin;
	int 			l;

	i = 0;
	l = 0;
	while (champ->champ_bin[i])
		i++;
	i += ft_strlen(line);
	bin = (unsigned char *)malloc(sizeof(unsigned char) * (i + 1));
	if (bin == NULL)
		threw("Error");
	while (champ->champ_bin[l])
	{
		bin[l] = champ->champ_bin[l];
		l++;
	}
	i = 0;
	while (line[i])
		bin[l] = line[i++];
	bin[l] = 0;
	if (champ->champ_bin)
		free(champ->champ_bin);
	champ->champ_bin = bin;
}
