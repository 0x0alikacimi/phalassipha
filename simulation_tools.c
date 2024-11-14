#include "philo.h"

void	eating(t_philo_data *ph)
{
	unsigned long	time;

	// pthread_mutex_lock(&ph->DiningAttributes->sign_mutex);
	// if (ph->DiningAttributes->end_sign)
	// {
	// 	pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex);
	// 	return ;
	// }
	// pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex);
	time = 0;
	pthread_mutex_lock(ph->right_fork);
	pthread_mutex_lock(ph->left_fork);
	printf("%lu %zu is eating\n", get_time(&time), ph->id);
	ph->last_eat = time;
	usleep(ph->DiningAttributes->t_eat * 1000);
	pthread_mutex_unlock(ph->right_fork);
	pthread_mutex_unlock(ph->left_fork);
}

void	sleeping(t_philo_data *ph)
{
	unsigned long	time;
	
	// pthread_mutex_lock(&ph->DiningAttributes->sign_mutex);
	// if (ph->DiningAttributes->end_sign)
	// {
	// 	pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex);
	// 	return ;
	// }
	// pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex);
	time = 0;
	printf("%lu %zu is sleeping\n", get_time(&time), ph->id);
	usleep(ph->DiningAttributes->t_slp * 1000);
}

void	thinking(t_philo_data *ph)
{
	unsigned long	time;

	// pthread_mutex_lock(&ph->DiningAttributes->sign_mutex);
	// if (ph->DiningAttributes->end_sign)
	// {
	// 	pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex);
	// 	return ;
	// }
	// pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex);
	time = 0;
	printf("%lu %zu is thinking \n", get_time(&time), ph->id);
}