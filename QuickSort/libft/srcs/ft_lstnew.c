/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:28:21 by samymone          #+#    #+#             */
/*   Updated: 2019/05/04 11:58:19 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list*)malloc(sizeof(t_list) * 1);
	if (fresh == NULL)
		return (NULL);
	if (content == NULL)
	{
		(*fresh).content = NULL;
		(*fresh).content_size = 0;
	}
	else
	{
		if (!((*fresh).content = malloc(sizeof(size_t) * content_size)))
		{
			free(fresh);
			return (NULL);
		}
		(*fresh).content_size = content_size;
		ft_memmove((*fresh).content, content, content_size);
	}
	(*fresh).next = NULL;
	return (fresh);
}
