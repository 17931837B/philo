#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	time_t			start_time;
	unsigned int	num_of_philos;
	pthread_t		monitor;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat;
	int				fin;
	pthread_mutex_t	fin_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*fork_lock;
	t_philo			**philos;
}	t_table;

typedef struct s_philo
{
	pthread_t			thread;
	unsigned int		id;
	unsigned int		eat_count;
	unsigned int		domi_fork;
	unsigned int		nondomi_fork;
	pthread_mutex_t		eating_time;
	time_t				last_eat;
	t_table				*table;
}	t_philo;

int		check_arg(int argc, char **argv);
t_table	*init_set(int argc, char **argv);
void	set_arg(int argc, char **argv, t_table *table);
time_t	now_time(void);
void	ft_printf(t_philo *philo, char *status);
int		is_alive(t_table *table);
void	sim_freeze(time_t freeze_time);
void	*normal_action(void *var);
void	*lonely_action(void *var);
void	*monitor(void *var);
void	set_action(t_table *table);

#endif