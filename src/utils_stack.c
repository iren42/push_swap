/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 04:01:56 by iren              #+#    #+#             */
/*   Updated: 2022/04/29 16:39:03 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		if (s[0] == '-' && s[1] != '\0')
			i++;
		while (s[i])
		{
			if (!ft_isdigit(s[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

static void	error_init_tint(t_int *val, t_list *res)
{
	ft_lstclear(&res, free);
	free(val);
	res = 0;
	ft_error();
}

t_list	*fill_stack(char **av, int ac)
{
	int			i;
	t_list		*res;
	t_list		*new;
	t_int		*val;
	long long	buff;

	i = 1;
	res = 0;
	while (i < ac)
	{
		val = malloc(sizeof(t_int));
		if (val && is_number(av[i]))
			buff = ft_atoil(av[i]);
		if (!val || !is_number(av[i]) || buff > INT_MAX || buff < INT_MIN)
			error_init_tint(val, res);
		else
			val->v = (int)buff;
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
