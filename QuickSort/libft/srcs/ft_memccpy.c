/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:24:19 by samymone          #+#    #+#             */
/*   Updated: 2019/04/17 19:40:05 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*s == ch)
		{
			*d = *s;
			return (++d);
		}
		else
		{
			*d = *s;
			s++;
			d++;
			n--;
		}
	}
	return (NULL);
}
