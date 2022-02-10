#include "philo.h"
#include <stdio.h>

int	get_params(int argc, char **argv, t_params *prm)
{
	prm->philos = ft_atoi(argv[1]);
	prm->time_to_die = ft_atoi(argv[2]);
	prm->time_eating = ft_atoi(argv[3]);
	prm->time_sleeping = ft_atoi(argv[4]);
	if (argc == 6)
		prm->must_eat_times = ft_atoi(argv[5]);
	if (!prm->philos || !prm->time_to_die
		|| !prm->time_eating || !prm->time_sleeping || !prm->must_eat_times)
	{
		write(1, "Invalid arguments\n", 18);
		return (-1);
	}
	printf("%d %ld %ld %ld %d\n", prm->philos, prm->time_to_die, prm->time_eating, prm->time_sleeping, prm->must_eat_times);
	return (0);
}

int	init_philos(t_philo *philos, t_params *params, t_fork *fork)
{
	int		i;

	i = -1;
	while (++i < params->philos)
	{
		fork[i].count = i;
		fork[i].free = 1;
	}
	i = -1;
	while (++i < params->philos)
	{
		philos[i].num = i + 1;
		philos[i].last_ate = 0;
		philos[i].has_eaten = 0;
		philos[i].left = fork;
		philos[i].right = &fork[i];
		if (i + 1 == params->philos)
			philos[i].left = &fork[0];
		else
			philos[i].left = &fork[i + 1];
		philos[i].prm = params;
	}
	return (i);
}

void	*live(void *philos)
{
	t_philo	*philo;

	philo = philos;
	return (0);
}

int	start_simulation(t_philo *philos, t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->philos)
	{
		pthread_create(&philos[i].ph_th, 0, live, &(philos[i]));
		//printf("philo %d, last_ate %d, has_eaten %d, left fork %d, right fork %d\n",
		//	philos[i].num, philos[i].last_ate, philos[i].has_eaten, philos[i].left->count, philos[i].right->count);
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
	return (0);
}