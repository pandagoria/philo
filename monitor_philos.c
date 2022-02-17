/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <hlaunch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:02:06 by hlaunch           #+#    #+#             */
/*   Updated: 2022/02/17 15:02:07 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_starved(t_philo *philo)
{
	struct timeval	now;

	pthread_mutex_lock(&philo->rewrite_lstate);
	gettimeofday(&now, 0);
	if (((now.tv_sec - philo->last_ate.tv_sec) * 1000) + ((now.tv_usec
				- philo->last_ate.tv_usec) / 1000) > philo->prm->time_to_die)
	{
		pthread_mutex_unlock(&philo->rewrite_lstate);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->rewrite_lstate);
		return (0);
	}
}

int	max_eat_times(t_philo *philos, t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->philos)
	{
		pthread_mutex_lock(&philos[i].rewrite_lstate);
		if (philos[i].has_eaten < params->must_eat_times)
		{
			pthread_mutex_unlock(&philos[i].rewrite_lstate);
			return (0);
		}
		pthread_mutex_unlock(&philos[i].rewrite_lstate);
	}
	return (1);
}

void	monitor_philos_state(t_philo *philos, t_params *params)
{
	int	i;

	i = -1;
	while (1)
	{
		if (++i >= params->philos)
		{
			i = 0;
			if (params->must_eat_times != -1 && max_eat_times(philos, params))
			{
				pthread_mutex_lock(&params->died);
				params->must_die = 1;
				pthread_mutex_unlock(&params->died);
				return ;
			}
		}
		if (is_starved(&philos[i]) == 1)
		{
			pthread_mutex_lock(&params->died);
			params->must_die = 1;
			pthread_mutex_unlock(&params->died);
			write_stdout("has died", &philos[i], 0);
			return ;
		}
	}
}
