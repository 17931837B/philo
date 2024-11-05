#include "philo.h"

static void	cycle_think_fast(t_philo *philo)
{
	time_t	time_to_think;

	time_to_think = 1;
	sim_freeze(time_to_think);
}

static void	cycle_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_lock[philo->domi_fork]);
	ft_printf(philo, "has taken a fork");
	pthread_mutex_lock(&philo->table->fork_lock[philo->nondomi_fork]);
	ft_printf(philo, "has taken a fork");
	ft_printf(philo, "is eating");
	pthread_mutex_lock(&philo->eating_time);
	philo->last_eat = now_time();
	pthread_mutex_unlock(&philo->eating_time);
	sim_freeze(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->domi_fork]);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->nondomi_fork]);
	pthread_mutex_lock(&philo->eating_time);
	// philo->last_eat = now_time();//加えるべきか
	philo->eat_count += 1;
	pthread_mutex_unlock(&philo->eating_time);
}

static void	cycle_sleep(t_philo *philo)
{
	ft_printf(philo, "is sleeping");
	sim_freeze(philo->table->time_to_sleep);
}

static void	cycle_think(t_philo *philo)
{
	ft_printf(philo, "is thinking");
}

void	*normal_action(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	pthread_mutex_lock(&philo->eating_time);
	philo->last_eat = philo->table->start_time;
	pthread_mutex_unlock(&philo->eating_time);
	while (now_time() < philo->table->start_time+500)
		continue ;
	ft_printf(philo, "----------------------------");
	if (philo->id % 2)
		cycle_think_fast(philo);
	while (is_alive(philo->table))
	{
		// ft_printf(philo, "----------------------------");
		cycle_eat(philo);
		cycle_sleep(philo);
		cycle_think(philo);
	}
	return (NULL);
}
