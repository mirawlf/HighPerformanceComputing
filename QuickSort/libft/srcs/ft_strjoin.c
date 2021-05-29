/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:46:15 by samymone          #+#    #+#             */
/*   Updated: 2019/04/17 17:54:56 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		l;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	fresh = (char*)malloc(sizeof(char) * (l + 1));
	if (fresh == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*fresh = *s1;
		fresh++;
		s1++;
	}
	while (*s2)
	{
		*fresh = *s2;
		fresh++;
		s2++;
	}
	*fresh = '\0';
	return (fresh - l);
}
