/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:18:24 by iren              #+#    #+#             */
/*   Updated: 2022/04/30 10:17:49 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define ERR_MSG "Error"

typedef struct s_ps
{
	int		ac;
	t_list	*a;
	t_list	*b;
}				t_ps;

typedef struct s_int
{
	int	v;
}				t_int;

void	init(t_ps *tt, char **av, int ac);

void	set_int(t_int *t, int val);
int		get_int(t_int *t);

t_list	*fill_stack(char **av, int ac);
void	free_ps(t_ps *ps);

void	ft_error(void);

void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);

int		is_sorted(t_list *l);
void	three_sort_a(t_ps *ps, t_list *lst);
void	three_sort_b(t_ps *ps, t_list *lst);
void	fourtosix_sort(t_ps *ps);

void	print_stacks(t_ps *p);

#endif
