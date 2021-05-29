#include "../includes/ft_push_swap.h"

t_elem					*ft_newelem(int num)
{
	t_elem				*elem;

	if (!(elem = ft_memalloc(sizeof(t_elem))))
		return (NULL);
	elem->next = elem;
	elem->prev = elem;
	elem->num = num;
	return (elem);
}

t_stack					*ft_newstack(void)
{
	t_stack				*stack;

	if (!(stack = ft_memalloc(sizeof(t_stack))))
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void					ft_cleanelem(t_elem **elem)
{
	if (!elem)
		return ;
	(*elem)->num = 0;
	(*elem)->next = NULL;
	(*elem)->prev = NULL;
	free(*elem);
}

void					ft_cleanstack(t_stack **stack)
{
	t_elem		*cur;
	t_elem		*tmp;

	if (!(cur = (*stack)->head))
		return ;
	while (cur != (*stack)->tail)
	{
		tmp = cur->next;
		cur->next = NULL;
		cur->num = 0;
		cur->prev = NULL;
		free(cur);
		cur = tmp;
	}
	free((*stack)->tail);
}

void					ft_addstack(t_elem *elem, t_stack **stack)
{
	if (!elem || !stack)
		ft_error();
	if (!(*stack))
		if (!(*stack = ft_newstack()))
			ft_error();
	if (!(*stack)->size)
	{
		(*stack)->head = elem;
		(*stack)->tail = elem;
		(*stack)->size = 1;
		(*stack)->head->next = (*stack)->tail;
		(*stack)->head->prev = (*stack)->tail;
		(*stack)->tail->next = (*stack)->head;
		(*stack)->tail->prev = (*stack)->head;
	}
	else
	{
		elem->prev = (*stack)->tail;
		elem->next = (*stack)->head;
		(*stack)->head->prev = elem;
		(*stack)->tail->next = elem;
		(*stack)->tail = elem;
		(*stack)->size += 1;
	}
}
