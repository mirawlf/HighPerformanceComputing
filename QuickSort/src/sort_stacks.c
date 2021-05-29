#include "../includes/ft_push_swap.h"

void			from_a_to_b(t_push_swap *ps, int min, int mid)
{
	int			i;
	int			size;

	i = 0;
	size = ps->a->size;
	while (i < size && ps->a->head && ps->a->head->num >= min
	&& min_mid_a(ps, min, mid) == 1)
	{
		while (ps->a->head && ps->a->head->num <= mid
		&& ps->a->head->num >= min)
		{
			ft_pb(ps);
			ft_putendl_fd("pb", 1);
			i++;
		}
		if (ps->a->head && ps->a->head->num >= min
		&& min_mid_a(ps, min, mid) == 1)
		{
			ft_ra(ps);
			ft_putendl_fd("ra", 1);
		}
		i++;
	}
}

void			quick_sort_a(t_push_swap *ps)
{
	int			max;
	int			min;
	int			mid;

	max = max_elem(ps->a);
	min = (ps->once_sorted == 0) ? min_elem(ps->a) :
			min_elem_sort(ps, ps->next_min);
	mid = (max - min) / 2 + min;
	mid = (max - mid < 3 || ps->a->size - ps->sort_nub < 3) ? max : mid;
	mid = (mid == ps->current_mid) ? mid + 2 : mid;
	if (ps->a->size < 4)
		small_stack(ps->a, ps, 'a');
	else
		from_a_to_b(ps, min, mid);
	while (ps->a && ps->a->tail && ps->a->tail->num >= min &&
	ps->once_sorted == 1 && !ft_is_sorted(ps))
	{
		ft_rra(ps);
		ft_putendl_fd("rra", 1);
	}
	ps->current_mid = mid;
	ps->once_sorted = 1;
}

void			from_b_to_a(t_push_swap *ps)
{
	int			i;
	//int 		ierr;
	//int 		prank;
	//int 		psize;

 	/*ierr = MPI_Init(NULL, NULL);
 	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &prank);
 	ierr = MPI_Comm_size(MPI_COMM_WORLD, &psize);*/

	i = 0;
	//if (prank == 0)
	//{
		while (ps->b->head != NULL && max_on_the_top_b(ps) != 1)
		{
			ps->sort_nub = ps->sort_nub + 1;
			ft_pa(ps);
			ft_putendl_fd("pa", 1);
			i++;
		}
	//}
	//if (prank == 1)
	//{
		while (i-- > 0)
		{
			ft_ra(ps);
			ft_putendl_fd("ra", 1);
		}
	//}
	//MPI_Barrier(MPI_COMM_WORLD);
	//MPI_Finalize();
}

void			quick_sort_b(t_push_swap *ps)
{
	int			max;
	int			min;
	int			mid;
	int			i;

	max = max_elem(ps->b);
	min = min_elem(ps->b);
	mid = (max - min) / 2 + min;
	i = ps->b->size;
	while (ps->b->head && i-- > 0)
	{
		while (ps->b->head && ps->b->head->num > mid)
		{
			ft_pa(ps);
			ft_putendl_fd("pa", 1);
			i--;
		}
		if (ps->b->size > 1)
		{
			ft_rb(ps);
			ft_putendl_fd("rb", 1);
		}
	}
	from_b_to_a(ps);
	ps->next_min = ps->a->tail->num + 1;
}
