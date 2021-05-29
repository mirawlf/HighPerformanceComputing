/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:42:24 by samymone          #+#    #+#             */
/*   Updated: 2019/05/24 16:44:08 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*t;
	size_t		i;

	i = 0;
	t = (char*)malloc((n + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	while (i < n)
	{
		t[i] = s1[i];
		i++;
	}
	t[i] = '\0';
	return ((char*)t);
}
