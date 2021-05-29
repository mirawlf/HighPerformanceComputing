#include "../includes/ft_push_swap.h"

unsigned char		ft_is_sorted(t_push_swap *ps)
{
	t_elem	*elem;

	if (ps->b != NULL && ps->b->head != NULL)
		return (0);
	if (ps->a->head != NULL)
	{
		elem = ps->a->head;
		while (elem != ps->a->tail)
		{
			if (elem->num > elem->next->num)
				return (0);
			else
				elem = elem->next;
		}
		return (1);
	}
	return (1);
}
