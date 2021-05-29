#include "../includes/ft_push_swap.h"

void		ft_clean_av(int ac, char **av)
{
	int		i;

	i = 1;
	if (av)
	{
		while (i < ac && av[i])
		{
			ft_strdel(&av[i]);
			i++;
		}
		free(av);
	}
}

void		ft_clean_input(int n, char **input)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_strdel(&input[i]);
		i++;
	}
	free(input);
}
