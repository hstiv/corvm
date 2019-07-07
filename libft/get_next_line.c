/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:06:25 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/22 19:03:54 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static t_list	*get_data(int fd, t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (!lst)
		return (NULL);
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(lst, tmp);
	tmp = *lst;
	return (tmp);
}

static int		read_from_file(const int fd, char **str)
{
	int		size;
	int		i;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	if (!(tmp = ft_strnew(1)))
		return (-1);
	while (((i = read(fd, buf, BUFF_SIZE)) > 0))
	{
		size = 0;
		while (buf[size] != '\n' && size < i)
			size++;
		if (!(tmp = join_lines(tmp, buf, i)))
			return (-1);
		if (size < i)
			break ;
	}
	if (!(*str = join_lines(*str, tmp, ft_strlen(tmp))))
		i = -1;
	ft_strdel(&tmp);
	return (i);
}

static int		save_static(char **line, t_list **list)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	tmp = (*list)->content;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	str[i] = '\0';
	str = ft_strncpy(str, tmp, i);
	if (!(*line = ft_strdup(str)))
		return (0);
	free(str);
	if (tmp[i])
	{
		(*list)->content = ft_strdup(&(((*list)->content)[i + 1]));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*save;
	t_list			*list;
	int				i;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || (read(fd, buf, 0) < 0)
		|| (!(list = get_data(fd, &save))))
		return (-1);
	tmp = list->content;
	i = read_from_file(fd, &tmp);
	if (i < 0)
		return (-1);
	list->content = tmp;
	if (!i && !*tmp && !ft_strlen(tmp))
		return (0);
	if (!(save_static(&(*line), &list)))
		return (-1);
	return (1);
}
