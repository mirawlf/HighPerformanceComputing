#include "../includes/ft_push_swap.h"

int			min_elem_sort(t_push_swap *ps, int curr_min)
{
	t_elem		*tmp;
	int			new_min;

	new_min = max_elem(ps->a);
	tmp = ps->a->head;
	while (tmp->next != ps->a->head)
	{
		if (tmp->num >= curr_min && tmp->num < new_min)
			new_min = tmp->num;
		tmp = tmp->next;
	}
	if (tmp->num >= curr_min && tmp->num < new_min)
		new_min = tmp->num;
	return (new_min);
}

int			max_elem(t_stack *stack)
{
	t_elem	*tmp;
	int		max;
	int		i;
	/*int psize, ierr;
	ierr = MPI_Comm_size(MPI_COMM_WORLD, &psize);
	int tmp2[stack->size];
	int tmp3[psize-1];
	printf("PSIZE %d\n", psize);*/

	tmp = stack->head;
	max = stack->head->num;
	//MPI_Scatter(stack, stack->size/psize, MPI_INT, tmp2, stack->size/psize, \
	//	MPI_INT,  0, MPI_COMM_WORLD);
	i = stack->size;
	while (i-- > 0)
	{
		if (tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	//MPI_Gather(tmp, 1, MPI_INT, tmp3, 1, MPI_INT, 0, MPI_COMM_WORLD);
	/*max = tmp3[0];
	for (int j = 1; j < psize; j++)
	{
		if (tmp3[j] > max)
			max = tmp3[j];
	}*/
	return (max);
}

int			min_elem(t_stack *stack)
{
	t_elem	*tmp;
	int		min;
	int		i;

	tmp = stack->head;
	min = stack->head->num;
	i = stack->size;
	while (i-- > 0)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

void		rotate_b(int st, int fh, t_push_swap *ps, int max)
{
	if (st <= fh)
		while (max != ps->b->head->num)
			ft_rb(ps);
	else if (fh < st)
		while (max != ps->b->head->num)
			ft_rrb(ps);
}

int			max_on_the_top_b(t_push_swap *ps)
{
	int		max;
	int		st;
	int		fh;
	t_elem	*tmp;

	max = max_elem(ps->b);
	st = 0;
	fh = 0;
	tmp = ps->b->head;
	while (tmp->num != max)
	{
		st++;
		tmp = tmp->next;
	}
	tmp = ps->b->tail;
	while (tmp->num != max)
	{
		fh++;
		tmp = tmp->prev;
	}
	rotate_b(st, fh, ps, max);
	return (ps->b->size > 0 ? 0 : 1);
}
