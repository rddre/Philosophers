



#include "../philo.h"

long long timestamp_ms(long long time)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000) - time);
}

void	init_data(t_data *data, char **av, int nb_arg)
{
	int	i;

	data->nb_philo = ft_atoi(av[1]);
	data->life_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);

	if (nb_arg == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;

	data->time = timestamp_ms(0);
	data->dead = 0;

	// Init du mutex de mort
	pthread_mutex_init(&data->death_mutex, NULL);

	// Allocation des forks
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return;

	// Init des forks (un mutex par fork)
	i = 0;
	while (i < data->nb_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
	data->fini = 0;
}

int	main(int nb_arg, char **av)
{
	t_data data;

	if (nb_arg != 5 && nb_arg != 6)
		return (print("Erreur : mauvais nombre d'argument\n"), 1);

	parsing( nb_arg, av);

	init_data(&data, av, nb_arg);

	philo(&data);
	
	return (1);
}
