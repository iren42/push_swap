/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:48:58 by iren              #+#    #+#             */
/*   Updated: 2022/04/30 10:09:37 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *l)
{
	if (l)
	{
		while (l->next)
		{
			if (get_int(l->content) > get_int(l->next->content))
				return (0);
			l = l->next;
		}
	}
	return (1);
}

void	three_sort_a(t_ps *ps, t_list *lst)
{
	if (lst && !is_sorted(lst))
	{
		if (get_int(lst->content) < get_int(lst->next->content)
			&& get_int(lst->content) < get_int(lst->next->next->content))
		{
			rra(ps);
			sa(ps);
		}
		else if (get_int(lst->content) > get_int(lst->next->content)
			&& get_int(lst->content) > get_int(lst->next->next->content))
		{
			ra(ps);
			if (!is_sorted(ps->a))
				sa(ps);
		}
		else
		{
			if (get_int(lst->next->content) == 0)
				sa(ps);
			else
				rra(ps);
		}
	}
}

void	three_sort_b(t_ps *ps, t_list *lst)
{
	if (lst && !is_sorted(lst))
	{
		if (get_int(lst->content) < get_int(lst->next->content)
			&& get_int(lst->content) < get_int(lst->next->next->content))
		{
			rrb(ps);
			sb(ps);
		}
		else if (get_int(lst->content) > get_int(lst->next->content)
			&& get_int(lst->content) > get_int(lst->next->next->content))
		{
			rb(ps);
			if (!is_sorted(ps->b))
				sb(ps);
		}
		else
		{
			if (get_int(lst->next->content) == 3)
				sb(ps);
			else
				rrb(ps);
		}
	}
}
