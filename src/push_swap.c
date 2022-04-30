/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:15:07 by iren              #+#    #+#             */
/*   Updated: 2022/04/30 10:10:45 by iren             ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_ps	tt;

	if (ac < 2)
		return (0);
	init(&tt, av, ac);
	if (is_sorted(tt.a))
		;
	else if (ac < 4)
		sa(&tt);
	else if (ac < 5)
		three_sort_a(&tt, tt.a);
	else if (ac < 8)
		fourtosix_sort(&tt);
	else
		radix_sort(&tt);
	free_ps(&tt);
	return (0);
}
