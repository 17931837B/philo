#include "philo.h"
//init_time_calculateのstart_time遅延

void	init_time_calculate(t_table *table)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	table->start_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) + 100;
}

time_t	now_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*lonely_action(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	if (!philo->table->must_eat)
		return (NULL);
	philo->last_meal = philo->table->start_time;
	while (now_time() < philo->table->start_time)
		continue ;
	printf("%ld %d %s\n", now_time() - philo->table->start_time, philo->id + 1, "has taken a fork");
	while (now_time() < philo->table->start_time + philo->table->time_to_die);
	printf("%ld %d %s\n", now_time() - philo->table->start_time, philo->id + 1, "died");

	return (NULL);
}

static void	set_simulate(t_table *table)
{
	int	i;

	i = 0;
	init_time_calculate(table);
	if (table->num_of_philos == 1)
		pthread_create(&table->philos[i]->thread, NULL, &lonely_action, table->philos[i]);

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
	set_simulate(table);


	usleep(5000000);
	return (EXIT_SUCCESS);
}
