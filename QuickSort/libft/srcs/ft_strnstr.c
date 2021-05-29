/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:37:38 by samymone          #+#    #+#             */
/*   Updated: 2019/05/05 17:24:58 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack && i < len)
	{
		if ((ft_strncmp(haystack, needle, ft_strlen(needle)) == 0) &&
		(ft_strlen(needle) + i - 1) < len)
		{
			if (i < len)
				return ((char*)haystack);
		}
		haystack++;
		i++;
	}
	return (NULL);
}
