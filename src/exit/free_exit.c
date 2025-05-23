

#include "../../philo.h"

void	exit_free(t_data *data, t_philo *philos, int code)
{
	int	i;

	if (data)
	{
		// Détruire les mutex des fourchettes
		if (data->forks)
		{
			i = 0;
			while (i < data->nb_philo)
				pthread_mutex_destroy(&data->forks[i++]);
			free(data->forks);
			data->forks = NULL;
		}
		// Détruire le mutex de mort
		pthread_mutex_destroy(&data->death_mutex);
	}

	// Libérer les philosophes s'ils existent
	if (philos)
	{
		free(philos);
		philos = NULL;
	}
	exit(code);
}
