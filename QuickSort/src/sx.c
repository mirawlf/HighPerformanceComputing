#include "../includes/ft_push_swap.h"

static void				ft_sx(t_stack *stack)
{
	t_elem				*tmp;
	t_elem				*tmp_2;

	if (!stack)
		return ;
	if (stack->size == 2)
	{
		stack->head = stack->head->next;
		stack->tail = stack->tail->next;
	}
	else if (stack->size > 2)
	{
		tmp = stack->head;
		tmp_2 = stack->head->next->next;
		stack->head = stack->head->next;
		stack->head->next = tmp;
		stack->head->prev = stack->tail;
		stack->tail->next = stack->head;
		tmp->prev = stack->head;
		tmp_2->prev = tmp;
		tmp->next = tmp_2;
	}
}

void					ft_sa(t_push_swap *ps)
{
	ft_sx(ps->a);
}

void					ft_sb(t_push_swap *ps)
{
	ft_sx(ps->b);
}

void					ft_ss(t_push_swap *ps)
{
	ft_sx(ps->a);
	ft_sx(ps->b);
}
