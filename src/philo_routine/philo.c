


#include "../../philo.h"


void	*routine(void *arg)
{
	t_philo	*philo;
	long long ts;

	philo = (t_philo *)arg;
	ts = philo->data->time;
	while (1)
	{
		printf("[ %lld ] Philo %d pense\n", timestamp_ms(ts), philo->id);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		printf("[ %lld ] Philo %d mange\n", timestamp_ms(ts), philo->id);
		usleep(philo->data->eat_time * 1000);
		philo->meals_eaten++;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		printf("[ %lld ] Philo %d dort\n", timestamp_ms(ts), philo->id);
		usleep(philo->data->sleep_time * 1000);

		if (philo->data->must_eat > 0 && philo->meals_eaten >= philo->data->must_eat)
		{
			printf("[ %lld ] Philo %d a fini\n", timestamp_ms(ts), philo->id);
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

void	philo(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philos)
		exit_free(data, NULL, 1);
	
//     initialisation + lancer tout les philo

	init_philosophers(data, philos);

//     on attend que les philo ont fini

	i = 0;
	while (i < data->nb_philo)
		pthread_join(philos[i++].thread, NULL);

	exit_free(data, philos, 0);
}
