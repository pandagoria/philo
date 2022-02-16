#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_params
{
	int		philos;
	long	time_to_die;
	long	time_eating;
	long	time_sleeping;
	int		must_eat_times;
	int		must_die;
	pthread_mutex_t	writing;
	struct timeval	prog_start;
}	t_params;

typedef struct s_fork
{
	int				count;
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
	pthread_mutex_t	rewrite_lstate;
}	t_philo;


#endif