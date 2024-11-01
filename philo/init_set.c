#include "philo.h"

static void	set_dominannt(t_philo *philo)
{
	if (philo->id % 2)
	{
		philo->domi_fork = (philo->id + 1);
		philo->nondomi_fork = philo->id;
	}
	else
	{
		philo->domi_fork = philo->id;
		philo->nondomi_fork = (philo->id + 1);
	}
	if (philo->id + 1 == philo->table->num_of_philos)
	{
		if (philo->id % 2)
			philo->domi_fork = 0;
		else
			philo->nondomi_fork = 0;
	}
}

static t_philo	**set_philos(t_table *table)
{
	t_philo		**philos;
	int			i;

	i = 0;
	philos = malloc(sizeof(t_philo) * table->num_of_philos);
	if (philos == NULL)
		return (NULL);
	while (i < table->num_of_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (philos[i] == NULL)
			return (NULL);
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			return (NULL);
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->time_ate = 0;
		set_dominannt(philos[i]);
		i++;
	}
	return (philos);
}

pthread_mutex_t	*set_fork(t_table *table)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * table->num_of_philos);
	if (forks == NULL)
		return (NULL);
	while (i < table->num_of_philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (NULL);
		i++;
	}
	return (forks);
}

static int	set_mutex(t_table *table)
{
	table->fork_locks = set_fork(table);
	if (!table->fork_locks)
		return (0);
	if (pthread_mutex_init(&table->sim_stop_lock, 0) != 0)
		return (1);
	if (pthread_mutex_init(&table->write_lock, 0) != 0)
		return (1);
	return (0);
}

t_table	*init_set(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (table == NULL)
		return (NULL);
	set_arg(argc, argv, table);
	table->philos = set_philos(table);
	if (table->philos == NULL)
		return (NULL);
	if (set_mutex(table))
		return (NULL);
	table->sim_stop = false;
	return (table);
}
