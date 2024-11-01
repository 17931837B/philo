// #include "philo.h"

// void	*action(void *var)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)var;
// 	if (!philo->table->must_eat)
// 		return (NULL);

// }

// void	*lonely_action(void *var)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)var;
// 	if (!philo->table->must_eat)
// 		return (NULL);

// 	philo->last_meal = philo->table->start_time;
// 	printf("%ld %d %s\n", get_time_in_ms() - philo->table->start_time, philo->id + 1, "has taken a fork");

// }