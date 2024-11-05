#include "philo.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
		{
			if (*str1 > *str2)
				return (1);
			else
				return (-1);
		}
		str1++;
		str2++;
	}
	return (0);
}

void	ft_printf(t_philo *philo, char *status)
{
	if (is_alive(philo->table) || !ft_strcmp(status, "died"))
	{
		pthread_mutex_lock(&philo->table->write_lock);
		printf("%ld	%3d %s\n", now_time() - philo->table->start_time,
			philo->id + 1, status);
		pthread_mutex_unlock(&philo->table->write_lock);
	}
}
