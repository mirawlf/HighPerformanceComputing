/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:02:18 by samymone          #+#    #+#             */
/*   Updated: 2019/05/09 14:48:08 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*res(char *s, int n)
{
	int	len;

	len = 11;
	if (n == 0)
	{
		if (!(s = (char *)ft_memalloc(sizeof(char) * 2)))
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
	}
	else if (n == -2147483648)
	{
		s = ft_strdup("-2147483648");
	}
	return (s);
}

static char		*extra_fun(int len, char *s, int n, int neg)
{
	if (!(s = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = '\0';
	while (n)
	{
		s[--len] = n % 10 + '0';
		n /= 10;
	}
	neg == 1 ? (s[--len] = '-') : 1;
	return (s);
}

char			*ft_itoa(int n)
{
	int		tmp_n;
	int		len;
	char	*s;
	int		neg;

	len = 0;
	tmp_n = n;
	neg = 0;
	s = NULL;
	if (n == 0 || n == -2147483648)
		return (res(s, n));
	if (n < 0)
	{
		len += 1;
		tmp_n *= -1;
		n *= -1;
		neg = 1;
	}
	while (tmp_n)
	{
		len++;
		tmp_n /= 10;
	}
	return (extra_fun(len, s, n, neg));
}
