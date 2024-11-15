#include "philo.h"

void	eating(t_philo_data *ph)
{
	unsigned long	time;

	time = 0;
	pthread_mutex_lock(ph->right_fork);
	pthread_mutex_lock(ph->left_fork);
	print_msg("is eating\n", ph, ph->id, time);
	ph->last_eat = time;
	usleep(ph->DiningAttributes->t_eat * 1000);
	pthread_mutex_unlock(ph->right_fork);
	pthread_mutex_unlock(ph->left_fork);
}

void	sleeping(t_philo_data *ph)
{
	unsigned long	time;

	time = 0;
	print_msg("is sleeping\n", ph, ph->id, time);
	usleep(ph->DiningAttributes->t_slp * 1000);
}

void	thinking(t_philo_data *ph)
{
	unsigned long	time;

	time = 0;
	print_msg("is thinking\n", ph, ph->id, time);
}