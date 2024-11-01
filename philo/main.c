#include "philo.h"
//init_time_calculateのstart_time遅延

void	init_time_calculate(t_table *table)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	table->start_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

static int	simulate(t_table *table)
{
	int	i;

	init_time_calculate(table);
	i = 0;
	while (i < table->num_of_philos)
	{
		pthread_create(&table->philos[i]->thread, NULL, &action, table->philos[i]);
		i++;
	}
	//next
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	table = init_set(argc, argv);
	if (table == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
	if (simulate(table))
		return (EXIT_FAILURE);
}
