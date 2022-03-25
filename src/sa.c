/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:10:47 by iren              #+#    #+#             */
/*   Updated: 2022/03/25 00:35:41 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps)
{
	t_list	*silver;

	if (!ps || ps->a == 0)
		;
	else
	{
		silver = ps->a->next;
		ps->a->next = ps->a->next->next;
		silver->next = 0;
		ft_lstadd_front(&ps->a, silver);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_ps *ps)
{
	t_list	*silver;

	if (!ps || ps->b == 0)
		;
	else
	{
		silver = ps->b->next;
		ps->b->next = ps->b->next->next;
		silver->next = 0;
		ft_lstadd_front(&ps->b, silver);
		ft_putstr_fd("sb\n", 1);
	}
}
