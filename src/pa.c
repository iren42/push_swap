/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:27:20 by iren              #+#    #+#             */
/*   Updated: 2022/03/25 20:22:16 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *ps)
{
	t_list	*topb;

	if (!ps || ps->b == 0)
		;
	else
	{
		topb = ps->b;
		ps->b = ps->b->next;
		topb->next = 0;
		ft_lstadd_front(&ps->a, topb);
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_ps *ps)
{
	t_list	*top;

	if (ps->a == 0 || ps == 0)
		;
	else
	{
		top = ps->a;
		ps->a = ps->a->next;
		top->next = 0;
		ft_lstadd_front(&ps->b, top);
		ft_putstr_fd("pb\n", 1);
	}
}
