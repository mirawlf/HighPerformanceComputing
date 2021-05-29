/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:52:21 by samymone          #+#    #+#             */
/*   Updated: 2019/05/09 14:16:17 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp;

	if (dst == src)
		return (dst);
	temp = (unsigned char*)src;
	if (dst < src)
		ft_memcpy(dst, (unsigned char*)temp, len);
	else if (dst > src)
		ft_revmemcpy(dst, (unsigned char*)temp, len);
	return (dst);
}
