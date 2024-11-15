#include "philo.h"

int	setup_philos(t_gen_data *gen)
{
	t_philo_data	*philos;
	size_t			i;

	philos = ft_allocate(0, gen->attr->n_phs * sizeof(t_philo_data));
	if (!philos)
		return(ft_allocate(36, 0), 1);
	i = 0;
	while (i < gen->attr->n_phs)
	{
		philos[i].right_fork = &(gen->forks[i]);
		philos[i].left_fork = &(gen->forks[(i + 1) % gen->attr->n_phs]);
		philos[i].id = i;
		get_time(&philos[i].last_eat);
		philos[i].DiningAttributes = gen->attr;
		gen->attr->end_sign = 0;
		i++;
	}
	gen->philos = philos;
	return (0);
}

int	setup_simulation(t_DiningAttr *attr, t_gen_data	*gen)
{
	size_t		i;

	gen->attr = attr;
	gen->forks = ft_allocate(0, gen->attr->n_phs * sizeof(pthread_mutex_t));
	if (!gen->forks)
		return (ft_allocate(36, 0), 1);
	i = 0;
	while (i < gen->attr->n_phs)
	{
		pthread_mutex_init(&gen->forks[i], NULL);
		i++;
	}
	// pthread_mutex_init(&gen->attr->print, NULL);
	return (0);
}