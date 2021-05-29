/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:13:05 by samymone          #+#    #+#             */
/*   Updated: 2019/05/04 16:23:37 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (src[i] && i < (int)len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
