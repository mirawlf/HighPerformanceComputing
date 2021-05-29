/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:55:59 by samymone          #+#    #+#             */
/*   Updated: 2019/05/24 17:01:38 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*fresh;
	int		l;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL || n > ft_strlen(s2))
		return (NULL);
	l = ft_strlen(s1) + n;
	fresh = (char*)malloc(sizeof(char) * (l + 1));
	if (fresh == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*fresh = *s1;
		fresh++;
		s1++;
	}
	while (i++ < n)
	{
		*fresh = *s2;
		fresh++;
		s2++;
	}
	*fresh = '\0';
	return (fresh - l);
}
