#include "../includes/ft_push_swap.h"

static t_stack			*ft_init_stack(int ac, char **av)
{
	t_elem				*elem;
	t_stack				*stack;
	int					arg_pos;

	if (!(ft_input_validation(ac, av)))
		ft_error();
	stack = NULL;
	arg_pos = 1;
	#pragma omp parallel
	while (arg_pos < ac)
	{
		if (!(elem = ft_newelem(ft_atoi(av[arg_pos]))))
			ft_error();
		ft_addstack(elem, &stack);
		arg_pos++;
	}
	if (ac == 2)
		ft_clean_av(ac, av);
	return (stack);
}

void					start_of_sorting(t_push_swap *ps)
{
	ps->is_sorted == 0 ? prep_sort(ps) : 1;
	ps->a != NULL ? ft_cleanstack(&ps->a) : 1;
	free(ps->b);
}

int						main(int ac, char **av)
{
	t_push_swap			ps;
	char				**input;
	int					i;
	/*int psize;
	int prank;
	int ierr;
	ierr = MPI_Init(NULL, NULL);
 	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &prank);
 	ierr = MPI_Comm_size(MPI_COMM_WORLD, &psize);*/

    //double start = MPI_Wtime();
    clock_t start = clock();
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		i = 0;
		input = ft_strsplit(av[1], ' ');
		while (input[i])
			i++;
		if (i++ == 0)
		{
			free(input);
			return (0);
		}
		av = parse_input(av, i, input);
		ac = i;
	}
	ft_bzero(&ps, sizeof(t_push_swap));
	ps.a = ft_init_stack(ac, av);
	start_of_sorting(&ps);
	//MPI_Finalize();

	//double end = MPI_Wtime();
	//double end = omp_get_wtime();
	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("Elapsed time: %f ms\n", seconds);
	exit(1);
}
