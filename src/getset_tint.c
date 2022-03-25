/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset_tint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:57:06 by iren              #+#    #+#             */
/*   Updated: 2022/03/23 14:27:13 by iren             ###   ########.fr       */
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

void	set_len(t_int *st, int val)
{
	st->len = val;
}

int	get_len(t_int *v)
{
	if (v != 0)
	{
		return (v->len);
	}
	return (0);
}
