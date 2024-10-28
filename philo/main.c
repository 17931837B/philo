#include "philo.h"

int	is_correct_num(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_only_disit)
			return (EXIT_FAILURE);
	}
}

int	check_arg(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	else if (is_correct_num(argc, argv))
		return (EXIT_FAILURE);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	return(check_arg(argc, argv));
}