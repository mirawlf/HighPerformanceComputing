/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:47:31 by samymone          #+#    #+#             */
/*   Updated: 2019/04/14 03:01:20 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char	*src;
	int				i;

	src = dst;
	i = 0;
	while (n != 0)
	{
		src[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (&src[0]);
}
