#include "philo.h"


void	*the_routine(void *arg)
{
	t_philo_data	*ph;

	ph = (t_philo_data	*)arg;
	if (ph->id % 2)
		usleep(50);

	while (1)
	{
		// pthread_mutex_lock(&ph->DiningAttributes->print);
		pthread_mutex_lock(&ph->DiningAttributes->sign_mutex);
		if (ph->DiningAttributes->end_sign)
			return (pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex), NULL);
		pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex);
		
		eating(ph);

		pthread_mutex_lock(&ph->DiningAttributes->sign_mutex);
		if (ph->DiningAttributes->end_sign)
			return (pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex), NULL);
		pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex);

		sleeping(ph);

		pthread_mutex_lock(&ph->DiningAttributes->sign_mutex);
		if (ph->DiningAttributes->end_sign)
			return (pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex), NULL);
		pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex);

		thinking(ph);
		// pthread_mutex_unlock(&ph->DiningAttributes->print);
	}
}

void *monitor(void *arg)
{
	t_gen_data		*gen;
	unsigned long	curr_time;
	size_t			i;

	gen = (t_gen_data *)arg;
	while (1)
	{
		i = 0;
		while (i < gen->attr->n_phs)
		{
			get_time(&curr_time);
			if (curr_time - gen->philos[i].last_eat > gen->attr->t_die)
			{
				printf("%lu %zu died--------------\n", curr_time, gen->philos[i].id);
				pthread_mutex_lock(&gen->attr->sign_mutex);
				gen->attr->end_sign = 1;
				pthread_mutex_unlock(&gen->attr->sign_mutex);
				return (NULL);
			}
			i++;
			// check if all have eaten enough and end
		}
		usleep(100); // Adjust as needed
	}
	return (NULL);
}


int	the_dining(t_gen_data *gen)
{
	pthread_t	*threads;
	pthread_t	monitor_thread;
	size_t		i;

	threads = ft_allocate(0, gen->attr->n_phs * sizeof(pthread_t));
	if (!threads)
		return (ft_allocate(36, 0), 1);
	i = 0;
	while (i < gen->attr->n_phs)
	{
		if (pthread_create(&threads[i], NULL, the_routine, &(gen->philos[i])) != 0)
			return (ft_allocate(36, 0), 1);
		i++;
	}
	pthread_create(&monitor_thread, NULL, monitor, gen);
	pthread_join(monitor_thread, NULL);
	i =  0;
	while (i < gen->attr->n_phs)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return (0);
}
