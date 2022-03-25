/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 22:08:49 by iren              #+#    #+#             */
/*   Updated: 2022/03/25 00:36:37 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	t_list	*top;

	if (ps->a == 0 || ps == 0)
		;
	else
	{
		top = ps->a;
		ps->a = ps->a->next;
		top->next = 0;
		ft_lstadd_back(&ps->a, top);
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_ps *ps)
{
	t_list	*top;

	if (ps->b == 0 || ps == 0)
		;
	else
	{
		top = ps->b;
		ps->b = ps->b->next;
		top->next = 0;
		ft_lstadd_back(&ps->b, top);
		ft_putstr_fd("rb\n", 1);
	}
}
