#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>

/* Holds general settings for the dining simulation */
typedef struct s_DiningAttr
{
	unsigned long	n_phs;			// Number of philosophers participating in the simulation
	unsigned long	t_die;			// Time (in ms) after which a philosopher dies if they do not eat
	unsigned long	t_eat;			// Time (in ms) it takes for a philosopher to complete eating
	unsigned long	t_slp;			// Time (in ms) a philosopher spends sleeping after eating
	unsigned long	num_meals;		// Number of times each philosopher must eat before the simulation ends
	int				end_sign;
	pthread_mutex_t	sign_mutex;
	pthread_mutex_t	print;
}		t_DiningAttr;

/* Represents individual philosopher's information and forks used during dining */
typedef struct s_philo_data
{
	size_t			id;
	pthread_mutex_t	*left_fork;			// Pointer to the left fork (mutex), shared with the philosopher on the left
	pthread_mutex_t	*right_fork;		// Pointer to the right fork (mutex), shared with the philosopher on the right
	t_DiningAttr	*DiningAttributes;	// Pointer to shared dining attributes, enabling access to the simulation’s settings
	unsigned long	last_eat;
} t_philo_data;

/* Stores shared resources and attributes for the simulation */
typedef struct	s_gen_data
{
	t_DiningAttr	*attr;			// The overall dining attributes used by all philosophers
	pthread_mutex_t	*forks;			// Array of mutexes representing forks. Each fork is shared between two philosophers.
	t_philo_data	*philos;
}	t_gen_data;

typedef struct s_gc_e
{
	void			*ptr;
	struct s_gc_e	*next;
}					t_gc_e;

void			ft_perror(char *str);
int				valid_n(char *str, unsigned long *nb);
void			print_msg(char *str, t_philo_data *ph, size_t i, unsigned long t);
int				pars_it(int ac, char **av, t_DiningAttr *th);
int				setup_simulation(t_DiningAttr *attr, t_gen_data	*gen);
int				setup_philos(t_gen_data *gen);
int				the_dining(t_gen_data *gen);

unsigned long	get_time(unsigned long *nb);
void			eating(t_philo_data *ph);
void			sleeping(t_philo_data *ph);
void			thinking(t_philo_data *ph);

void			*ft_allocate(int flag, int size);

#endif