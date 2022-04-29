/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 15:44:33 by iren              #+#    #+#             */
/*   Updated: 2022/04/29 17:21:01 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *st, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = 0;
	while (c < 0)
		c += 256;
	while (c > 256)
		c -= 256;
	while (st[i])
	{
		if (c == st[i])
			res = (char *)&st[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&st[i]);
	return ((char *)res);
}
