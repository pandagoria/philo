/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <hlaunch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:01:49 by hlaunch           #+#    #+#             */
/*   Updated: 2022/02/17 15:01:52 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_params *params, t_fork *fork)
{
	int	i;

	i = -1;
	while (++i < params->philos)
	{
		fork[i].count = i;
		pthread_mutex_init(&fork[i].mutex, 0);
	}
}

int	init_philos(t_philo *philos, t_params *params, t_fork *fork)
{
	int		i;

	i = -1;
	while (++i < params->philos)
	{
		philos[i].num = i + 1;
		philos[i].has_eaten = 0;
		philos[i].left = fork;
		if (i + 1 == params->philos)
		{
			philos[i].right = &fork[0];
			philos[i].left = &fork[i];
		}
		else
		{
			philos[i].left = &fork[i + 1];
			philos[i].right = &fork[i];
		}
		philos[i].prm = params;
		pthread_mutex_init(&philos[i].rewrite_lstate, 0);
	}
	return (i);
}

static int	check_valid_params(t_params *prm)
{
	return (prm->philos <= 200 && prm->time_eating >= 60
		&& prm->time_sleeping >= 60 && prm->time_to_die >= 60);
}

static int	not_digits(const char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	return (0);
}

int	init_params(int argc, char **argv, t_params *prm)
{
	if (not_digits(argv[1]) || not_digits(argv[2])
		|| not_digits(argv[3]) || not_digits(argv[4]))
		return (-1);
	if (argc == 6 && not_digits(argv[5]))
		return (-1);
	prm->philos = ft_atoi(argv[1]);
	prm->time_to_die = ft_atoi(argv[2]);
	prm->time_eating = ft_atoi(argv[3]);
	prm->time_sleeping = ft_atoi(argv[4]);
	if (argc == 6)
		prm->must_eat_times = ft_atoi(argv[5]);
	else
		prm->must_eat_times = -1;
	if (!prm->philos || !prm->time_to_die
		|| !prm->time_eating || !prm->time_sleeping
		|| !(check_valid_params(prm)))
	{
		error_manage();
		return (-1);
	}
	prm->must_die = 0;
	pthread_mutex_init(&prm->died, 0);
	pthread_mutex_init(&prm->writing, 0);
	return (0);
}
