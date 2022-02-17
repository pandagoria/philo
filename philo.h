/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <hlaunch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:02:17 by hlaunch           #+#    #+#             */
/*   Updated: 2022/02/17 15:02:18 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_params
{
	int				philos;
	long			time_to_die;
	long			time_eating;
	long			time_sleeping;
	int				must_eat_times;
	int				must_die;
	pthread_mutex_t	writing;
	pthread_mutex_t	died;
	struct timeval	prog_start;
}	t_params;

typedef struct s_fork
{
	int				count;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int				num;
	pthread_t		ph_th;
	int				has_eaten;
	struct timeval	last_ate;
	t_fork			*left;
	t_fork			*right;
	t_params		*prm;
	pthread_mutex_t	rewrite_lstate;
}	t_philo;

int		ft_atoi(const char *str);
int		write_stdout(char *str, t_philo *philo, int flag);
int		init_philos(t_philo *philos, t_params *params, t_fork *fork);
int		init_params(int argc, char **argv, t_params *prm);
int		is_starved(t_philo *philo);;
int		max_eat_times(t_philo *philos, t_params *params);
void	init_forks(t_params *params, t_fork *fork);
void	my_sleep(long ms);
void	monitor_philos_state(t_philo *philos, t_params *params);
void	error_manage(void);

#endif