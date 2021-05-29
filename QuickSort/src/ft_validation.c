#include "../includes/ft_push_swap.h"

static unsigned char	ft_all_int(int ac, char **av)
{
	int					pos;
	char				*tmp;

	pos = 1;
	while (pos < ac)
	{
		tmp = ft_itoa(ft_atoi(av[pos]));
		if (!ft_strequ(av[pos], tmp))
		{
			ft_strdel(&tmp);
			return (0);
		}
		ft_strdel(&tmp);
		pos++;
	}
	return (1);
}

static unsigned char	ft_no_duplicates(int ac, char **av)
{
	int					i;
	int					j;

	i = 1;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

unsigned char			ft_input_validation(int ac, char **av)
{
	return (ft_all_int(ac, av) && ft_no_duplicates(ac, av));
}

char					**parse_input(char **av, int i, char **input)
{
	int j;

	j = 0;
	av = (char**)malloc(sizeof(char*) * i);
	while (j++ < i - 1)
		av[j] = ft_strdup(input[j - 1]);
	ft_clean_input(j, input);
	return (av);
}
