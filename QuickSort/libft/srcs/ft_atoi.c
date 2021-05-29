/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <samymone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:45:21 by samymone          #+#    #+#             */
/*   Updated: 2019/05/09 14:43:59 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	diffspaces(const char *str)
{
	if (*str == '\n' || *str == ' ' || *str == '\r' || *str == '\t' ||
	*str == '\f' || *str == '\v')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int			is_neg;
	long int	res;

	res = 0;
	is_neg = 1;
	while (diffspaces(str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res * 10 / 10 == res)
			res = res * 10 + *str - '0';
		str++;
	}
	return (res * is_neg);
}
