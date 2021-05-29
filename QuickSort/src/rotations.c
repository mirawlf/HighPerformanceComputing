#include "../includes/ft_push_swap.h"

void			small_stack(t_stack *stack, t_push_swap *ps, char ch)
{
	if (stack->size == 2)
	{
		if (mid_sorting(stack) == 0)
		{
			if (ch == 'a')
			{
				ft_sa(ps);
				ft_putendl_fd("sa", 1);
			}
			else if (ch == 'b')
			{
				ft_sb(ps);
				ft_putendl_fd("sb", 1);
			}
		}
	}
	else
		min_num_of_operations(stack, ps, ch);
}

void			three_rotation_for_a(t_stack *stack, t_push_swap *ps)
{
	if (stack->head->num > stack->head->next->num &&
		stack->head->num > stack->tail->num)
	{
		ft_ra(ps);
		ft_putendl_fd("ra", 1);
	}
	if (stack->head->num > stack->head->next->num)
	{
		ft_sa(ps);
		ft_putendl_fd("sa", 1);
	}
	if (stack->tail->num < stack->tail->prev->num)
	{
		ft_rra(ps);
		ft_putendl_fd("rra", 1);
	}
}

void			three_rotation_for_b(t_stack *stack, t_push_swap *ps)
{
	if (stack->head->num > stack->head->next->num &&
		stack->head->num > stack->tail->num)
	{
		ft_rb(ps);
		ft_putendl_fd("rb", 1);
	}
	if (stack->head->num > stack->head->next->num)
	{
		ft_sb(ps);
		ft_putendl_fd("sb", 1);
	}
	if (stack->tail->num < stack->tail->prev->num)
	{
		ft_rrb(ps);
		ft_putendl_fd("rrb", 1);
	}
}
