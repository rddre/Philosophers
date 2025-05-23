

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

		pthread_mutex_lock(&philo->data->death_mutex);
		philo->last_meal_time = timestamp_ms(philo->data->time);
		pthread_mutex_unlock(&philo->data->death_mutex);


		philo->meals_eaten++;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);

		if (philo->data->dead == 1)
			break;

		printf("[ %lld ] Philo %d dort\n", timestamp_ms(ts), philo->id);
		usleep(philo->data->sleep_time * 1000);

		if (philo->data->dead == 1)
			break;

		if (philo->data->must_eat > 0 && philo->meals_eaten >= philo->data->must_eat)
		{
			printf("[ %lld ] Philo %d a fini\n", timestamp_ms(ts), philo->id);
			break;
		}
	}
	return (NULL);
}
