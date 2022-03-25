/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 04:01:56 by iren              #+#    #+#             */
/*   Updated: 2022/03/25 21:43:22 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_tint(t_int *nb)
{
	printf("%d\n", nb->v);
}


void	print_list(t_list *l)
{
	int	*v;
	int	i;

	i = 0;
	while (l != 0)
	{
		print_tint(l->content);
		l = l->next;
	}
}

void	print_stacks(t_ps *pp)
{
	int	*v;
	int	i;

	i = 0;
	printf("---AAAA\n");
	print_list(pp->a);
	printf("---BBBB\n");
	print_list(pp->b);
}

t_list	*fill_stack(char **av, int ac)
{
	int	i;
	t_list	*res;
	t_list	*new;
	t_int	*val;

	i = 1;
	res = 0;
	while (i < ac)
	{
		val = malloc(sizeof(t_int));
		val->v = ft_atoi(av[i]);
		new = ft_lstnew(val);
		ft_lstadd_back(&res, new);
		i++;
	}
	return (res);
}

void	free_ps(t_ps *ll)
{
	if (ll->a != 0)
	{
		ft_lstclear(&ll->a, free);
		ll->a = 0;
	}
	if (ll->b != 0)
	{
		ft_lstclear(&ll->b, free);
		ll->b = 0;
	}
}
