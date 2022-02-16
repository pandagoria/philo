#include "philo.h"
#include <stdio.h>

int	get_params(int argc, char **argv, t_params *prm)
{
	prm->philos = ft_atoi(argv[1]);
	if (prm->philos > 300)
		return (1);
	prm->time_to_die = ft_atoi(argv[2]);
	prm->time_eating = ft_atoi(argv[3]);
	prm->time_sleeping = ft_atoi(argv[4]);
	if (argc == 6)
		prm->must_eat_times = ft_atoi(argv[5]);
	else
		prm->must_eat_times = -1;
	if (!prm->philos || !prm->time_to_die
		|| !prm->time_eating || !prm->time_sleeping)
	{
		write(1, "Invalid arguments\n", 18);
		return (-1);
	}
	prm->must_die = 0;
	pthread_mutex_init(&prm->writing, 0);
	return (0);
}

int	init_philos(t_philo *philos, t_params *params, t_fork *fork)
{
	int		i;

	i = -1;
	while (++i < params->philos)
	{
		fork[i].count = i;
		pthread_mutex_init(&fork[i].mutex, 0);
	}
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

int	write_stdout(char *str, t_philo *philo, int flag)
{
	struct timeval	now;
	long			tmp;

	gettimeofday(&now, 0);
	pthread_mutex_lock(&philo->prm->writing);
	tmp = ((now.tv_usec - philo->prm->prog_start.tv_usec) / 1000) + ((now.tv_sec - philo->prm->prog_start.tv_sec) * 1000);
	if (flag == 1)
		printf("%ld %d has taken forks\n%ld %d is eating\n", tmp, philo->num, tmp, philo->num);
	else
		printf("%ld %d %s\n", tmp, philo->num, str);
	pthread_mutex_unlock(&philo->prm->writing);
	return (0);
}

int	is_starved(t_philo *philo)
{
	struct timeval	now;

	pthread_mutex_lock(&philo->rewrite_lstate);
	gettimeofday(&now, 0);
	if (((now.tv_sec - philo->last_ate.tv_sec) * 1000) + ((now.tv_usec - philo->last_ate.tv_usec) / 1000) > philo->prm->time_to_die)
	{
		philo->prm->must_die = 1;
		//printf("%ld\n", ((now.tv_sec - philo->last_ate.tv_sec) * 1000) + ((now.tv_usec - philo->last_ate.tv_usec) / 1000));
		pthread_mutex_unlock(&philo->rewrite_lstate);
		return(1);
	}
	else
	{
		pthread_mutex_unlock(&philo->rewrite_lstate);
		return(0);
	}
}

void	my_sleep(long ms)
{
	struct timeval	now;
	struct timeval	tmp;

	gettimeofday(&now, 0);
	gettimeofday(&tmp, 0);
	while (((tmp.tv_sec - now.tv_sec) * 1000) + ((tmp.tv_usec - now.tv_usec) / 1000) < ms)
	{
		usleep(10);
		gettimeofday(&tmp, 0);
	}
}

int	eat(t_philo *philo)
{
	my_sleep(philo->prm->time_eating);
	pthread_mutex_lock(&philo->rewrite_lstate);
	gettimeofday(&philo->last_ate, 0);
	if (philo->prm->must_eat_times != -1 && philo->has_eaten < philo->prm->must_eat_times)
		philo->has_eaten++;
	pthread_mutex_unlock(&philo->rewrite_lstate);
	pthread_mutex_unlock(&philo->right->mutex);
	pthread_mutex_unlock(&philo->left->mutex);
	return (0);
}

void	*live(void *philos)
{
	t_philo		*philo;
	t_params	*prm;

	philo = philos;
	prm = philo->prm;
	gettimeofday(&philo->last_ate, 0);
	pthread_mutex_lock(&philo->rewrite_lstate);
	if (philo->num % 2 == 0)
		usleep(100);
	pthread_mutex_unlock(&philo->rewrite_lstate);
	while (prm->must_die != 1)
	{
		pthread_mutex_lock(&philo->right->mutex);
		pthread_mutex_lock(&philo->left->mutex);
		write_stdout("", philo, 1);
		if (eat(philo) == 1)
			return (NULL);
		write_stdout("is sleeping", philo, 0);
		my_sleep(prm->time_sleeping);
		write_stdout("is thinking", philo, 0);
	}
	return (NULL);
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
	params->must_die = 1;
	return (1);
}

int	start_simulation(t_philo *philos, t_params *params)
{
	int	i;

	i = -1;
	gettimeofday(&params->prog_start, 0);
	while (++i < params->philos)
	{
		pthread_create(&philos[i].ph_th, 0, live, &(philos[i]));
		// pthread_detach(philos[i].ph_th);
	}
	while (1)
	{
		if (i >= params->philos)
		{
			i = 0;
			if (params->must_eat_times != -1 && max_eat_times(philos, params) == 1)
				return (0);
		}
		if (is_starved(&philos[i]) == 1)
		{
			write_stdout("has died", &philos[i], 0);
			return(0);
		}
		i++;
	}
	return (0);
}

void	gameover(t_philo *philo, t_fork *forks, t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->philos)
		pthread_join(philo[i].ph_th, 0);
	while (++i < params->philos)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		pthread_mutex_destroy(&philo[i].rewrite_lstate);
	}
	pthread_mutex_destroy(&params->writing);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_philo		philos[200];
	t_fork		fork[200];

	if (argc != 5 && argc != 6)
		return (1);
	if (get_params(argc, argv, &params) < 0)
		return (1);
	if (init_philos((t_philo *) philos, &params, fork) < 0)
		return (1);
	if (start_simulation((t_philo *) philos, &params) < 0)
		return (1);
	gameover((t_philo *) philos, (t_fork *) fork, &params);
	return (0);
}
