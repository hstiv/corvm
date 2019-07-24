/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:56:39 by sdiedra           #+#    #+#             */
/*   Updated: 2019/07/12 15:50:55 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corvm.h"

void	champ_error(void)
{
	char 		*s;

	s = "Error: can't open champion file\n";
	write(1, s, ft_strlen(s));
	exit(0);
}

void	parse_champs(t_vm *vm, char *name, int n, int number)
{
	int	fd;
	int	i;

	if ((fd = open(name, O_RDONLY)) < 0)
		champ_error();
	if ((i = read(fd, &(vm->champs[n].magic), sizeof(int))) < 0)
		champ_error();
	if ((i = read(fd, &(vm->champs[n].name), PROG_NAME_LENGTH)) < 0)
		champ_error();
	lseek(fd, 4, SEEK_CUR);
	if ((i = read(fd, &(vm->champs[n].exec_code), sizeof(int))) < 0)
		champ_error();
	if ((i = read(fd, &(vm->champs[n].comment), COMMENT_LENGTH)) < 0)
		champ_error();
	lseek(fd, 4, SEEK_CUR);
	if ((i = read(fd, &(vm->champs[n].champ_bin), CHAMP_MAX_SIZE)) < 0)
		champ_error();
	if (i > CHAMP_MAX_SIZE)
		champ_error();
	vm->champs[n].exec_code = i;
	vm->champs[n].n_place = number;
	vm->champs[n].live = 0;
	vm->champs[n].lives_in_period = 0;
	close(fd);
}
