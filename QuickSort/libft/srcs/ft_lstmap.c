/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:34:13 by samymone          #+#    #+#             */
/*   Updated: 2019/05/04 18:04:47 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_del_content(void *content, size_t content_size)
{
	if (content)
		free(content);
	content_size = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;

	if (lst == NULL || !f)
		return (NULL);
	if (!(fresh = malloc(sizeof(t_list))))
		return (NULL);
	fresh = f(lst);
	if (lst->next)
	{
		if (!(fresh->next = ft_lstmap(lst->next, f)))
		{
			ft_lstdel(&fresh, ft_del_content);
			return (NULL);
		}
	}
	return (fresh);
}
