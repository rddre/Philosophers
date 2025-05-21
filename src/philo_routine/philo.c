


#include "../../philo.h"


void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		printf("Philo %d pense\n", philo->id);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		printf("Philo %d mange\n", philo->id);
		usleep(philo->data->eat_time * 1000);
		philo->meals_eaten++;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		printf("Philo %d dort\n", philo->id);
		usleep(philo->data->sleep_time * 1000);

		if (philo->data->must_eat > 0 && philo->meals_eaten >= philo->data->must_eat)
		{
			printf("Philo %d a fini\n", philo->id);
			break;
		}
	}
	return (NULL);
}

void	init_philosophers(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].data = data;
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		i++;
	}
}

int	philo(t_data *data)
{
	int		i;
	t_philo	*philos;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->nb_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
	philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philos)
		return (1);
	
	init_philosophers(data, philos);

	i = 0;
	while (i < data->nb_philo)
		pthread_join(philos[i++].thread, NULL);
	return (0);
}
