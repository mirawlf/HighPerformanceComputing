/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:00:22 by samymone          #+#    #+#             */
/*   Updated: 2019/04/17 18:21:15 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	ch;

	ch = (unsigned char)c;
	a = (unsigned char*)s;
	while (n != 0)
	{
		if (*a == ch)
			return ((void*)a);
		a++;
		n--;
	}
	return (NULL);
}
