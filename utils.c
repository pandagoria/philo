/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <hlaunch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:02:12 by hlaunch           #+#    #+#             */
/*   Updated: 2022/02/17 15:02:13 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_manage(void)
{
	write(1, "Invalid arguments\n", 18);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	number;

	i = 0;
	minus = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	return (number * minus);
}

void	my_sleep(long ms)
{
	struct timeval	now;
	struct timeval	tmp;

	gettimeofday(&now, 0);
	gettimeofday(&tmp, 0);
	while (((tmp.tv_sec - now.tv_sec) * 1000)
		+ ((tmp.tv_usec - now.tv_usec) / 1000) < ms)
	{
		usleep(10);
		gettimeofday(&tmp, 0);
	}
}

int	write_stdout(char *str, t_philo *philo, int flag)
{
	struct timeval	now;
	long			tmp;

	gettimeofday(&now, 0);
	pthread_mutex_lock(&philo->prm->writing);
	tmp = ((now.tv_usec - philo->prm->prog_start.tv_usec) / 1000)
		+ ((now.tv_sec - philo->prm->prog_start.tv_sec) * 1000);
	if (flag == 1)
		printf("%ld %d has taken forks\n%ld %d is eating\n",
			tmp, philo->num, tmp, philo->num);
	else
		printf("%ld %d %s\n", tmp, philo->num, str);
	if (flag != 2)
		pthread_mutex_unlock(&philo->prm->writing);
	return (0);
}
