#include "../includes/ft_push_swap.h"

static void		ft_rx(t_stack *stack)
{
	if (!stack || !stack->head)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void			ft_ra(t_push_swap *ps)
{
	ft_rx(ps->a);
}

void			ft_rb(t_push_swap *ps)
{
	ft_rx(ps->b);
}

void			ft_rr(t_push_swap *ps)
{
	ft_rx(ps->a);
	ft_rx(ps->b);
}
