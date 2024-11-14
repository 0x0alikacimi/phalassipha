#include "philo.h"

void	setup_philos(t_gen_data *gen)
{
	t_philo_data	*philos;
	size_t			i;

	philos = ft_allocate(0, gen->attr->n_phs * sizeof(t_philo_data));
	i = 0;
	while (i < gen->attr->n_phs)
	{
		philos[i].right_fork = &(gen->forks[i]);
		philos[i].left_fork = &(gen->forks[(i + 1) % gen->attr->n_phs]);
		philos[i].id = i;
		get_time(&philos[i].last_eat);
		gen->attr->end_sign = 0;
		i++;
	}
	gen->philos = philos;
}

void	setup_simulation(t_DiningAttr *attr, t_gen_data	*gen)
{
	size_t		i;

	gen = NULL;
	i = 0;
	gen = ft_allocate(0, sizeof(t_gen_data));
	gen->attr = attr;
	gen->philo_id = ft_allocate(0, gen->attr->n_phs * sizeof(int));
	gen->forks = ft_allocate(0, gen->attr->n_phs * sizeof(pthread_mutex_t));
	while (i < gen->attr->n_phs)
	{
		pthread_mutex_init(&gen->forks[i], NULL);
		i++;
	}
	puts("saline hna\n");
	exit(0);
}