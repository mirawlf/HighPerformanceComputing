/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:26:19 by samymone          #+#    #+#             */
/*   Updated: 2019/09/09 16:26:22 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_value(int value, int base)
{
	int i;

	i = 0;
	while (value /= base)
		i++;
	return (i + 1);
}

char		*ft_itoa_base(int value, int base, char c)
{
	char	*returned;
	int		len;

	len = len_value(value, base);
	if (!(returned = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	returned[len--] = '\0';
	if (base == 8)
		while (len > -1)
		{
			returned[len--] = value % base + '0';
			value /= base;
		}
	else if (base == 16)
		while (len > -1)
		{
			if (value % base >= 10 && value % base <= 16 && c == 'X')
				returned[len--] = value % base + 7 + '0';
			else if (value % base >= 10 && value % base <= 16 && c == 'x')
				returned[len--] = value % base + 39 + '0';
			else
				returned[len--] = value % base + '0';
			value /= base;
		}
	return (returned);
}
