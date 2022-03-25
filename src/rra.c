/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:06:42 by iren              #+#    #+#             */
/*   Updated: 2022/03/25 00:37:38 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps *ps)
{
	t_list	*last;
	t_list	*before_last;
	t_list	*pa;

	if (ps->a == 0 || ps == 0)
		;
	else
	{
		pa = ps->a;
		last = ft_lstlast(ps->a);
		while (pa->next)
		{
			before_last = pa;
			pa = pa->next;
		}
		before_last->next = 0;
		pa->next = 0;
		ft_lstadd_front(&ps->a, last);
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_ps *ps)
{
	t_list	*last;
	t_list	*before_last;
	t_list	*pb;

	if (ps->b == 0 || ps == 0)
		;
	else
	{
		pb = ps->b;
		last = ft_lstlast(ps->b);
		while (pb->next)
		{
			before_last = pb;
			pb = pb->next;
		}
		before_last->next = 0;
		pb->next = 0;
		ft_lstadd_front(&ps->b, last);
		ft_putstr_fd("rrb\n", 1);
	}
}
