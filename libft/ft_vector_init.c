/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiedra <sdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:55:07 by sdiedra           #+#    #+#             */
/*   Updated: 2019/04/05 19:13:05 by sdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_vector_init(t_vector *v, int cap)
{
	v->capacity = cap;
	v->total = 0;
	v->items = malloc(sizeof(void *) * v->capacity);
}
