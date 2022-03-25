/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 22:42:32 by iren              #+#    #+#             */
/*   Updated: 2020/09/03 10:11:25 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *ptr;

	(void)ptr;
	while (*lst)
	{
		del((*lst)->content);
		ptr = (*lst);
		*lst = (*lst)->next;
		free(ptr);
	}
}
