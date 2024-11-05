#include "philo.h"

void	free_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		free(table->philos[i]);
		i++;
	}
	free(table->philos);
	free(table->fork_lock);
	free(table);
}

void	throw_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		pthread_mutex_destroy(&table->philos[i]->eating_time);
		pthread_mutex_destroy(&table->fork_lock[i]);
		i++;
	}
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->fin_lock);
}

void	fin_action(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philos)
	{
		pthread_join(table->philos[i]->thread, NULL);
		i++;
	}
	if (table->num_of_philos != 1)
		pthread_join(table->monitor, NULL);
	throw_all(table);
	free_all(table);
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
	set_action(table);
	fin_action(table);
	return (EXIT_SUCCESS);
}
