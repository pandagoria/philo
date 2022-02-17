/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <hlaunch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:01:57 by hlaunch           #+#    #+#             */
/*   Updated: 2022/02/17 15:01:58 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat(t_philo *philo)
{
	my_sleep(philo->prm->time_eating);
	pthread_mutex_lock(&philo->rewrite_lstate);
	gettimeofday(&philo->last_ate, 0);
	if (philo->prm->must_eat_times != -1)
		philo->has_eaten++;
	pthread_mutex_unlock(&philo->rewrite_lstate);
	pthread_mutex_unlock(&philo->right->mutex);
	pthread_mutex_unlock(&philo->left->mutex);
	return (0);
}

static void	*live(void *philo)
{
	gettimeofday(&((t_philo *)philo)->last_ate, 0);
	pthread_mutex_lock(&((t_philo *)philo)->rewrite_lstate);
	if (((t_philo *)philo)->num % 2 == 0)
		usleep(100);
	pthread_mutex_unlock(&((t_philo *)philo)->rewrite_lstate);
	while (1)
	{
		pthread_mutex_lock(&((t_philo *)philo)->right->mutex);
		pthread_mutex_lock(&((t_philo *)philo)->left->mutex);
		write_stdout("", philo, 1);
		eat(philo);
		write_stdout("is sleeping", philo, 0);
		my_sleep(((t_philo *)philo)->prm->time_sleeping);
		write_stdout("is thinking", philo, 0);
		pthread_mutex_lock(&((t_philo *)philo)->prm->died);
		if (((t_philo *)philo)->prm->must_die == 1)
		{
			pthread_mutex_unlock(&((t_philo *)philo)->prm->died);
			return (0);
		}
		pthread_mutex_unlock(&((t_philo *)philo)->prm->died);
	}
	return (NULL);
}

static void	start_simulation(t_philo *philos, t_params *params)
{
	int	i;

	i = -1;
	gettimeofday(&params->prog_start, 0);
	while (++i < params->philos)
	{
		pthread_create(&philos[i].ph_th, 0, live, &(philos[i]));
		pthread_detach(philos[i].ph_th);
	}
	monitor_philos_state(philos, params);
}

void	hueta(t_philo *philo, t_fork *forks, t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->philos)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		pthread_mutex_destroy(&philo[i].rewrite_lstate);
	}
	pthread_mutex_destroy(&params->writing);
	pthread_mutex_destroy(&params->died);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_philo		philos[200];
	t_fork		fork[200];

	if (argc != 5 && argc != 6)
		error_manage();
	if (init_params(argc, argv, &params) < 0)
		error_manage();
	init_forks(&params, fork);
	if (init_philos((t_philo *) philos, &params, fork) < 0)
		error_manage();
	start_simulation((t_philo *) philos, &params);
	usleep((params.time_eating + params.time_sleeping) * 2000);
	hueta((t_philo *) philos, (t_fork *) fork, &params);
	return (0);
}

//usleep((params.time_eating + params.time_sleeping) * 2000);