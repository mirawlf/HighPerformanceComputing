/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:06:11 by samymone          #+#    #+#             */
/*   Updated: 2019/10/01 14:06:13 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddback(t_list **list, void *content, size_t content_size)
{
	t_list *tmp;

	if (!list)
		return (NULL);
	if (!(*list))
	{
		if (!(*list = ft_lstnew(content, content_size)))
			return (NULL);
	}
	else if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_lstnew(content, content_size)))
			return (NULL);
	}
	return (*list);
}
