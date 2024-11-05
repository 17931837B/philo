#include "philo.h"

time_t	now_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	is_alive(t_table *table)
{
	int	res;

	res = 1;
	pthread_mutex_lock(&table->fin_lock);
	if (table->fin == 1)
		res = 0;
	pthread_mutex_unlock(&table->fin_lock);
	return (res);
}

void	sim_freeze(time_t freeze_time)
{
	time_t	att;

	att = now_time();
	while (now_time() < att + freeze_time)
		continue ;
}
