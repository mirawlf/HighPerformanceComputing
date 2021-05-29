/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:11:03 by samymone          #+#    #+#             */
/*   Updated: 2019/04/12 19:18:19 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*a;
	const char	*b;

	a = s1;
	b = s2;
	while (n != 0)
	{
		if (*a == *b)
		{
			a++;
			b++;
		}
		else
			return ((unsigned char)(*a) - (unsigned char)(*b));
		n--;
	}
	return (0);
}
