#include "../includes/ft_push_swap.h"

static void		ft_px(t_stack **stack_a, t_stack **stack_b)
{
	t_elem	*tmp;

	if ((*stack_b) != NULL && (*stack_b)->head != NULL)
	{
		tmp = (*stack_b)->head;
		(*stack_b)->head = (*stack_b)->head->next;
		(*stack_b)->tail->next = (*stack_b)->head;
		(*stack_b)->head->prev = (*stack_b)->tail;
		(*stack_b)->size -= 1;
		if ((*stack_b)->size == 0)
		{
			ft_bzero((*stack_b), sizeof(t_stack));
			if ((*stack_b)->head != NULL)
				ft_bzero((*stack_b)->head, sizeof(t_stack));
			if ((*stack_b)->tail != NULL)
				ft_bzero((*stack_b)->tail, sizeof(t_stack));
		}
		ft_addstack(tmp, stack_a);
		if ((*stack_a)->size)
		{
			(*stack_a)->head = (*stack_a)->tail;
			(*stack_a)->tail = (*stack_a)->tail->prev;
		}
	}
}

void			ft_pa(t_push_swap *ps)
{
	ft_px(&ps->a, &ps->b);
}

void			ft_pb(t_push_swap *ps)
{
	ft_px(&ps->b, &ps->a);
}
