/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourtosix_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 10:07:41 by iren              #+#    #+#             */
/*   Updated: 2022/04/30 10:11:31 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_each_stack(t_ps *ps)
{
	if (ps->a && ps->b)
	{
		if (ft_lstsize(ps->a) > 2)
			three_sort_a(ps, ps->a);
		else if (is_sorted(ps->a))
			;
		else
			sa(ps);
		if (ft_lstsize(ps->b) > 2)
			three_sort_b(ps, ps->b);
		else if (!is_sorted(ps->b))
			;
		else
			sb(ps);
	}
}

static void	empty_b(t_ps *ps)
{
	int	count;

	if (ps->b)
	{
		count = 0;
		if (ft_lstsize(ps->a) == 3 && ft_lstsize(ps->b) == 3)
		{
			while (ps->b != 0)
			{
				pa(ps);
				ra(ps);
			}
		}
		else
		{
			while (ps->b != 0)
			{
				pa(ps);
				count++;
			}
			while (count-- != 0)
				ra(ps);
		}
	}
}

void	fourtosix_sort(t_ps *ps)
{
	int	mid;

	if (ps->a)
	{
		mid = (ps->ac - 2) / 2;
		while (ft_lstsize(ps->a) - ft_lstsize(ps->b) > 1)
		{
			if (get_int(ps->a->content) > mid)
				pb(ps);
			else
				ra(ps);
		}
		sort_each_stack(ps);
		empty_b(ps);
	}	
}
