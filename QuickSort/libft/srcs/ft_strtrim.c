/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 23:00:33 by samymone          #+#    #+#             */
/*   Updated: 2019/05/04 16:27:11 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	spaces(char const *s)
{
	size_t		sp;
	int			i;

	sp = 0;
	i = 0;
	if (ft_strlen(s) > 0)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		sp = i;
		i = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\0')
		{
			i--;
			sp++;
		}
		return (sp);
	}
	return (0);
}

static size_t	first_char(char const *s)
{
	size_t		f;

	f = 0;
	while (s[f] == ' ' || s[f] == '\t' || s[f] == '\n')
		f++;
	return (f);
}

static size_t	last_char(char const *s)
{
	size_t		l;

	if (ft_strlen(s) > 0)
	{
		l = ft_strlen(s) - 1;
		while (s[l] == ' ' || s[l] == '\t' || s[l] == '\n' || s[l] == '\0')
			l--;
		return (l);
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char		*fresh;
	size_t		f;
	size_t		l;

	if (s == NULL)
		return (NULL);
	f = first_char(s);
	l = last_char(s);
	if (ft_strlen(s) == f)
	{
		fresh = (char*)malloc(sizeof(char));
		*fresh = '\0';
		return (fresh);
	}
	fresh = (char*)malloc(sizeof(char) * (ft_strlen(s) - spaces(s) + 1));
	if (fresh == NULL)
		return (NULL);
	ft_strncpy(fresh, (char*)&s[f], l - f + 1);
	fresh[l - f + 1] = '\0';
	return (fresh);
}
