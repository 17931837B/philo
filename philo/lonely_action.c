#include "philo.h"

void	*lonely_action(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	philo->last_eat = philo->table->start_time;
	while (now_time() < philo->table->start_time)
		continue ;
	ft_printf(philo, "has taken a fork");
	while (now_time() < philo->table->start_time + philo->table->time_to_die)
		continue ;
	ft_printf(philo, "died");
	return (NULL);
}
