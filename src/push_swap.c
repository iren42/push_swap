/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:15:07 by iren              #+#    #+#             */
/*   Updated: 2022/03/25 21:22:18 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_ps *tt)
{
	int	max_bits;
	int	max_num;
	int	i;
	int	j;

	max_bits = 0;
	max_num = tt->ac - 2;
	while ((max_num >> max_bits) != 0)
	{
		i = -1;
		while (i++ < max_bits)
		{
			j = -1;
			while (j++ < tt->ac - 2)
			{
				if (((get_int(tt->a->content) >> i) & 1) == 1)
					ra(tt);
				else
					pb(tt);
			}
			while (tt->b != 0)
				pa(tt);
		}
		max_bits++;
	}
}

void	medium_sort(t_ps *ps)
{
	int		mid;

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
		if (ft_lstsize(ps->a) > 2)
			mini_sort_a(ps, ps->a);
		else if (is_sorted(ps->a))
			;
		else
			sa(ps);
		if (ft_lstsize(ps->b) > 2)
			mini_sort_b(ps, ps->b);
		else if (is_sorted(ps->b))
			;
		else
			sb(ps);
		while (ft_lstsize(ps->b) != 0)
		{
			pa(ps);
			ra(ps);
		}
	}	
}

int	main(int ac, char **av)
{
	t_ps	tt;

	if (ac < 2)
		ft_error();
	init(&tt, av, ac);
	if (is_sorted(tt.a))
		;
	else if (ac < 4)
		sa(&tt);
	else if (ac < 5)
		mini_sort_a(&tt, tt.a);
	else if (ac < 8)
		medium_sort(&tt);
	else
		radix_sort(&tt);
	print_stacks(&tt);
	free_ps(&tt);
	return (0);
}
