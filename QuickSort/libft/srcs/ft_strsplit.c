/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <samymone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 13:12:36 by samymone          #+#    #+#             */
/*   Updated: 2019/05/04 18:58:05 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words(char const *s, char c)
{
	size_t	split;
	size_t	num;
	int		i;

	split = 0;
	num = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			num++;
		if (s[i] == c && split == 0)
			split = 1;
		else if (s[i] != c && split == 1)
		{
			split = 0;
			num++;
		}
		i++;
	}
	num++;
	return (num);
}

static size_t	chars(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	len++;
	return (len);
}

static char		**del(char **fresh)
{
	int i;

	i = 0;
	while (fresh[i])
	{
		free(fresh[i]);
		i++;
	}
	free(fresh);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	num;
	size_t	i;
	size_t	k;
	char	**fresh;

	if (!s || !(fresh = (char**)malloc(sizeof(char*) * (words(s, c)))))
		return (NULL);
	num = 0;
	i = words(s, c);
	while (num < (i - 1))
	{
		while (*s == c && *s)
			s++;
		if (*s != c && !(k = 0))
		{
			if (!(fresh[num] = (char*)malloc(sizeof(char) * (chars(s, c)))))
				return (del(fresh));
			while (*s != c && *s)
				fresh[num][k++] = *s++;
			fresh[num][k] = '\0';
		}
		num++;
	}
	fresh[num] = NULL;
	return (fresh);
}
