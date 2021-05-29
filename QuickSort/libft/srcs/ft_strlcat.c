/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:12:59 by samymone          #+#    #+#             */
/*   Updated: 2019/05/01 13:45:16 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l1;
	size_t	l2;
	size_t	i;

	l1 = ft_strlen(dst);
	l2 = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (l2);
	if (l1 > size - 1)
		return (l2 + size);
	while (l1 + i < size - 1)
	{
		dst[l1 + i] = src[i];
		i++;
	}
	dst[l1 + i] = '\0';
	return (l1 + l2);
}
