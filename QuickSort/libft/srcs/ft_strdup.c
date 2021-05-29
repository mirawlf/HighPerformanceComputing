/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:54:34 by samymone          #+#    #+#             */
/*   Updated: 2019/04/22 14:03:12 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*t;
	int			i;

	i = 0;
	t = (char*)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		t[i] = s1[i];
		i++;
	}
	t[i] = '\0';
	return ((char*)t);
}
