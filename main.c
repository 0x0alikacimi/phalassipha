#include "philo.h"

int main (int ac, char **av)
{
	t_DiningAttr	attr;
	t_gen_data		gen;

	if (ac < 5 || ac > 6)
	{
		ft_perror("Invalid number of args");
		return (1);
	}
	if (pars_it(ac, av, &attr) == 1)
		return (ft_allocate(36, 0), 1);
	if (pars_it(ac, av, &attr) == 1)
		return (ft_allocate(36, 0), 1);
	if (setup_simulation(&attr, &gen) != 0)
		return (1);
	if (setup_philos(&gen) != 0)
		return (1);
    the_dining(&gen);
}
