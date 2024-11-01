#include "philo.h"

void	set_arg(int argc, char **argv, t_table *table)
{
	table->num_of_philos = atoi(argv[1]);
	table->time_to_die = atoi(argv[2]);
	table->time_to_eat = atoi(argv[3]);
	table->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		table->must_eat = atoi(argv[5]);
	else
		table->must_eat = -1;
}
