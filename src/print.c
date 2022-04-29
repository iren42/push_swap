/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:22:47 by iren              #+#    #+#             */
/*   Updated: 2022/04/29 16:23:12 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_tint(t_int *nb)
{
	printf("%d\n", nb->v);
}

void	print_list(t_list *l)
{
	while (l != 0)
	{
		print_tint(l->content);
		l = l->next;
	}
}

void	print_stacks(t_ps *pp)
{
	printf("---AAAA\n");
	print_list(pp->a);
	printf("---BBBB\n");
	print_list(pp->b);
}
