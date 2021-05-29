/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:36:23 by samymone          #+#    #+#             */
/*   Updated: 2019/05/09 14:16:17 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	t;
	size_t			l;

	t = (unsigned char)c;
	l = ft_strlen(s);
	while (l > 0)
	{
		if (s[l] == t)
			return ((char*)(s + l));
		l--;
	}
	if (s[0] == t)
		return ((char*)s);
	return (NULL);
}
