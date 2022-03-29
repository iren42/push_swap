/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 03:56:18 by iren              #+#    #+#             */
/*   Updated: 2022/03/29 14:29:20 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(t_list *tt)
{
	t_list	*p1;
	t_list	*p2;

	p1 = tt;
	while (p1)
	{
		p2 = p1->next;
		while (p2)
		{
			if (get_int(p1->content) == get_int(p2->content))
				return (1);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	return (0);
}

static void	simplify_nb(t_ps *pp)
{
	t_list	*p1;
	t_list	*p2;
	t_list	*pa;
	int		val;

	pa = pp->a;
	p1 = pp->b;
	while (p1)
	{
		p2 = pp->b;
		val = 0;
		while (p2)
		{
			if (p1 == p2)
				;
			else if (get_int(p1->content) > get_int(p2->content))
				val++;
			p2 = p2->next;
		}
		set_int(pa->content, val);
		pa = pa->next;
		p1 = p1->next;
	}
}

void	init(t_ps *tt, char **av, int ac)
{
	tt->ac = ac;
	tt->a = fill_stack(av, ac);
	tt->b = fill_stack(av, ac);
	if (has_duplicate(tt->a))
	{
		free_ps(tt);
		ft_error();
	}
	simplify_nb(tt);
	ft_lstclear(&tt->b, free);
	tt->b = 0;
}
