/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:15:07 by iren              #+#    #+#             */
/*   Updated: 2022/04/29 21:15:03 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_max_bits(t_ps *tt)
{
	int	max_num;
	int	res;

	max_num = tt->ac - 2;
	res = 0;
	while ((max_num >> res) != 0)
		++res;
	return (res);
}

static void	radix_sort(t_ps *tt)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = ft_lstsize(tt->a);
	max_bits = calc_max_bits(tt);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((get_int(tt->a->content) >> i) & 1) == 1)
				ra(tt);
			else
				pb(tt);
		}
		while (tt->b != 0)
			pa(tt);
		i++;
	}
}

static void	sort_each_stack(t_ps *ps)
{
	if (ps->a && ps->b)
	{
		if (ft_lstsize(ps->a) > 2)
			mini_sort_a(ps, ps->a);
		else if (!is_sorted(ps->a))
			;
		else
			sa(ps);
		if (ft_lstsize(ps->b) > 2)
			mini_sort_b(ps, ps->b);
		else if (!is_sorted(ps->b))
			;
		else
			sb(ps);
	}
}

static void	medium_sort(t_ps *ps)
{
	int	mid;
	int	count;

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
		count = 0;
		while (ps->b != 0)
		{
			pa(ps);
			count++;
		}
		while (count-- != 0)
			ra(ps);
	}	
}

int	main(int ac, char **av)
{
	t_ps	tt;

	if (ac < 3)
		return (0);
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
	free_ps(&tt);
	return (0);
}
