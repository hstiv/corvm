/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:04:11 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/05 19:07:31 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_add(t_vector *v, void *item)
{
	if (v->capacity == v->total)
		ft_vector_resize(v, v->capacity * 2);
	v->items[v->total++] = item;
}
