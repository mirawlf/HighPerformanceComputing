/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:32:29 by samymone          #+#    #+#             */
/*   Updated: 2019/05/09 14:16:17 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;

	if (size + 1 == 0)
		return (NULL);
	fresh = (char*)malloc(size + 1);
	if (fresh == NULL)
		return (NULL);
	ft_memset(fresh, '\0', size + 1);
	return (fresh);
}
