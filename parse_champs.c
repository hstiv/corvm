/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:56:39 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/04 15:33:58 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corvm.h"

void	champ_error(void)
{
	ft_putstr("Error: can't open champion file\n");
	exit(0);
}

void	parse_champs(t_vm *vm, char *name, int n, int number)
{
	int	fd;

	if ((fd = open(name, O_RDONLY)) == -1)
		champ_error();
	read(fd, &(vm->champs[n].magic), sizeof(int));
	read(fd, &(vm->champs[n].name), PROG_NAME_LENGTH);
	lseek(fd, 4, SEEK_CUR);
	read(fd, &(vm->champs[n].exec_code), sizeof(int));
	read(fd, &(vm->champs[n].comment), COMMENT_LENGTH);
	lseek(fd, 4, SEEK_CUR);
	read(fd, &(vm->champs[n].champ_bin), CHAMP_MAX_SIZE);
	vm->champs[n].n_place = number;
	close(fd);
}
