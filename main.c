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
	if (!prm->philos || !prm->time_to_die
		|| !prm->time_eating || !prm->time_sleeping)
	{
		write(1, "Invalid arguments\n", 18);
		return (-1);
	}
	pthread_mutex_init(&prm->writing, 0);
	printf("%d %ld %ld %ld\n", prm->philos, prm->time_to_die, prm->time_eating, prm->time_sleeping);
	return (0);
}

int	init_philos(t_philo *philos, t_params *params, t_fork *fork)
{
	int		i;

	i = -1;
	while (++i < params->philos)
	{
		fork[i].count = i;
		fork[i].free = TRUE;
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
	}
	return (i);
}

void	gameover(t_philo *philo)
{

}

int	write_stdout(t_philo *philo, int flag)
{
	struct timeval	now;

	pthread_mutex_lock(&philo->prm->writing);
	gettimeofday(&now, 0);
	if (flag == EATING)
		printf("%d %d philo is eating\n", philo->last_ate.tv_usec / 1000, philo->num);
	else if (flag == DYING)
		printf("%d %d philo has died\n", now.tv_usec / 1000, philo->num);
	else if (flag == FORK_1 || flag == FORK_2)
		printf("%d %d philo has taken fork %d\n", now.tv_usec / 1000, philo->num, flag);
	else if (flag == SLEEPING)
		printf("%d %d philo is sleeping\n", now.tv_usec / 1000, philo->num);
	else if (flag == THINKING)
		printf("%d %d philo is thinking\n", now.tv_usec / 1000, philo->num);
	pthread_mutex_unlock(&philo->prm->writing);
	return (0);
}

int	is_starved(t_philo *philo)
{
	struct timeval	now;

	gettimeofday(&now, 0);
	//printf("%d %d %ld %d\n", now.tv_usec, philo->last_ate.tv_usec, philo->prm->time_to_die, (now.tv_usec - philo->last_ate.tv_usec) / 1000);
	if ((((now.tv_usec - philo->last_ate.tv_usec) / 1000) >= philo->prm->time_to_die))
		return(1);
	else
		return(0);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->right->mutex);
	write_stdout(philo, FORK_1);
	if (is_starved(philo))
		write_stdout(philo, DYING);
	printf("TUT\n");
	pthread_mutex_lock(&philo->left->mutex);
	write_stdout(philo, FORK_2);
	return (0);
}

int	eat(t_philo *philo)
{
	gettimeofday(&philo->last_ate, 0);
	write_stdout(philo, EATING);
	usleep(philo->prm->time_eating * 1000);
	gettimeofday(&philo->last_ate, 0);
	pthread_mutex_unlock(&philo->right->mutex);
	pthread_mutex_unlock(&philo->left->mutex);
	return (0);
}

void	*live(void *philos)
{
	t_philo	*philo;
	t_params	*prm;

	philo = philos;
	prm = philo->prm;
	while (1)
	{
		take_forks(philo);
		if (is_starved(philo))
			write_stdout(philo, DYING);
		eat(philo);
		write_stdout(philo, SLEEPING);
		usleep(prm->time_sleeping * 1000);
		if (is_starved(philo))
			write_stdout(philo, DYING);
		write_stdout(philo, THINKING);
	}

	return NULL;
}

int	start_simulation(t_philo *philos, t_params *params)
{
	int	i;

	i = -1;
	if (params->philos == 1)
		write_stdout(philos, DYING);
	while (++i < params->philos)
	{
		gettimeofday(&philos[i].last_ate, 0);
		pthread_create(&philos[i].ph_th, 0, live, &(philos[i]));
		printf("philo %d, last_ate %d, has_eaten %d, left fork %d, right fork %d\n",
			philos[i].num, philos[i].last_ate.tv_usec / 1000, philos[i].has_eaten, philos[i].left->count, philos[i].right->count);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_philo		philos[200];
	t_fork		fork[200];

	if (argc < 5)
		return (1);
	if (get_params(argc, argv, &params) < 0)
		return (1);
	if (init_philos((t_philo *) philos, &params, fork) < 0)
		return (1);
	if (start_simulation((t_philo *) philos, &params) < 0)
		return (1);
	int i = -1;
	while (++i < params.philos)
	{
		pthread_mutex_destroy(&fork[i].mutex);
	}
	return (0);
}

//когда умирают, философы должны выйти из вечного цикла.
//Джойнить все треды, а только потом мьютексы дестроить.