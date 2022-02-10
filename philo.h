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
}	t_params;

typedef struct s_fork
{
	int	count;
	int	free;
}	t_fork;


typedef struct s_philo
{
	int			num;
	pthread_t	ph_th;
	int			last_ate;
	int			has_eaten;
	t_fork		*left;
	t_fork		*right;
	t_params	*prm;
}	t_philo;


#endif