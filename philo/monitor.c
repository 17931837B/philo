#include "philo.h"

static int	good_bye(t_philo *philo)
{
	time_t	time;

	time = now_time();
	if ((time - philo->last_eat) >= philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->table->fin_lock);
		philo->table->fin = 1;
		pthread_mutex_unlock(&philo->table->fin_lock);
		ft_printf(philo, "died");
		pthread_mutex_unlock(&philo->eating_time);
		return (1);
	}
	return (0);
}

static int	is_ate_count(t_table *table, int i)
{
	if (table->must_eat != -1)
		if (table->philos[i]->eat_count < table->must_eat)
			return (0);
	return (1);
}

static int	check_alive(t_table *table)
{
	int	i;
	int	is_ate;

	i = 0;
	is_ate = 1;
	while (i < table->num_of_philos)
	{
		pthread_mutex_lock(&table->philos[i]->eating_time);
		if (good_bye(table->philos[i]))
			return (1);
		if (!is_ate_count(table, i))
			is_ate = 0;
		pthread_mutex_unlock(&table->philos[i]->eating_time);
		i++;
	}
	if (table->must_eat != -1 && is_ate == 1)
	{
		pthread_mutex_lock(&table->fin_lock);
		table->fin = 1;
		pthread_mutex_unlock(&table->fin_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *var)
{
	t_table	*table;

	table = (t_table *)var;
	while (now_time() < table->start_time)
		continue ;
	while (1)
	{
		if (check_alive(table))
			return (NULL);
	}
	return (NULL);
}
