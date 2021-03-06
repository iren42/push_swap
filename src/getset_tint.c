/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset_tint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:57:06 by iren              #+#    #+#             */
/*   Updated: 2022/03/29 14:31:56 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_int(t_int *st, int val)
{
	st->v = val;
}

int	get_int(t_int *v)
{
	if (v != 0)
	{
		return (v->v);
	}
	return (0);
}
