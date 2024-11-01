#include "philo.h"

static unsigned long long int	ft_atoi(char *num)
{
	unsigned long long int	res;
	int						i;

	i = 0;
	res = 0;
	while (num[i] && ('0' <= num[i] && num[i] <= '9'))
	{
		res = res * 10 + (num[i] - '0');
		i++;
	}
	return (res);
}

static int	is_only_disit(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] < '0' || '9' < num[i])
			return (1);
		i++;
	}
	return (0);
}

static int	is_correct_num(int argc, char **argv)
{
	int						i;
	unsigned long long int	num;

	i = 1;
	while (i < argc)
	{
		if (is_only_disit(argv[i]))
			return (EXIT_FAILURE);
		num = ft_atoi(argv[i]);
		if (num > INT_MAX)
			return (EXIT_FAILURE);
		if (i == 1 && num == 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_arg(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	else if (is_correct_num(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
