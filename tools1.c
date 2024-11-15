#include "philo.h"

unsigned long	get_time(unsigned long *nb)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	*nb = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (*nb);
}

void	ft_perror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	valid_n(char *str, unsigned long *nb)
{
	unsigned long	res;
	unsigned long	check;
	int				i;
	
	res = 0;
	i = 0;
	while ((str[i]) == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '\0' || str[i] < '0' || str[i] > '9')
		return(ft_perror("invalid arg\n"), 1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (ft_perror("invalid arg\n"), 1);
		check = res;
		res = res * 10 + (str[i] - '0');
		if (res / 10 != check)
			return (ft_perror("invalid arg\n"), 1);
		i++;
	}
	return (*nb = res, 0);
}

void	print_msg(char *str, t_philo_data *ph, size_t i, unsigned long t)
{
	pthread_mutex_lock(&ph->DiningAttributes->print);
	printf("%lu %zu %s", get_time(&t), i, str);
	pthread_mutex_lock(&ph->DiningAttributes->sign_mutex);
	if (ph->DiningAttributes->end_sign)
	{
		pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex);
		return ;
	}
	pthread_mutex_unlock(&ph->DiningAttributes->sign_mutex);
	pthread_mutex_unlock(&ph->DiningAttributes->print);
}