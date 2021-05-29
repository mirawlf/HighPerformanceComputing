/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:34:21 by samymone          #+#    #+#             */
/*   Updated: 2019/04/30 16:29:58 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t l1;
	size_t l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (n < l2)
	{
		ft_strncpy(&(s1[l1]), s2, n);
		s1[l1 + n] = '\0';
	}
	else
	{
		ft_strncpy(&(s1[l1]), s2, l2);
		s1[l1 + l2] = '\0';
	}
	return (s1);
}
