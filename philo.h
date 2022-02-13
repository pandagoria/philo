#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define EATING 3
# define SLEEPING 4
# define THINKING 5
# define DYING 6
# define FORK_1 1
# define FORK_2 2

typedef struct s_params
{
	int		philos;
	long	time_to_die;
	long	time_eating;
	long	time_sleeping;
	int		must_eat_times;
	pthread_mutex_t	writing;
}	t_params;

typedef struct s_fork
{
	int				count;
	int				free;
	pthread_mutex_t	mutex;
}	t_fork;


typedef struct s_philo
{
	int			num;
	pthread_t	ph_th;
	int			has_eaten;
	struct timeval	last_ate;
	t_fork		*left;
	t_fork		*right;
	t_params	*prm;
}	t_philo;


#endif