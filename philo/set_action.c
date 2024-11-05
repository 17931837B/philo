#include "philo.h"

static void	init_time_calculate(t_table *table)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	table->start_time = now_time() + (table->num_of_philos * 20);
}

void	set_action(t_table *table)
{
	int	i;

	i = 0;
	init_time_calculate(table);
	if (table->num_of_philos == 1)
		pthread_create(&table->philos[i]->thread, NULL,
			&lonely_action, table->philos[i]);
	else
	{
		while (i < table->num_of_philos)
		{
			pthread_create(&table->philos[i]->thread, NULL,
				&normal_action, table->philos[i]);
			i++;
		}
		pthread_create(&table->monitor, NULL, &monitor, table);
	}
}
