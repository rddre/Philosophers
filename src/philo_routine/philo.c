


#include "../../philo.h"

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
	
//      le monitoring

	pthread_t monitor_thread;
	pthread_create(&monitor_thread, NULL, monitoring, philos);

//     initialisation + lancer tout les philo

	init_philosophers(data, philos);

//     on attend que les philo ont fini

	i = 0;
	while (i < data->nb_philo)
		pthread_join(philos[i++].thread, NULL);

	data->fini = 1;

	pthread_join(monitor_thread, NULL);

	exit_free(data, philos, 0);
}
