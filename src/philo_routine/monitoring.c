

#include "../../philo.h"

void *monitoring(void *arg)
{
    t_philo *philos = (t_philo *)arg;
    t_data *data = philos[0].data;
    int i;

    while (1)
    {
        i = 0;
        while (i < data->nb_philo)
        {
            long long now = timestamp_ms(data->time);

            // Check if philosopher i died
            pthread_mutex_lock(&data->death_mutex);

            if (data->fini == 1)
                return NULL;
            if ((now - philos[i].last_meal_time) > data->life_time)
            {
                data->dead = 1;
                pthread_mutex_unlock(&data->death_mutex);
                printf("[ %lld ] Philo %d est mort\n", now, philos[i].id);
                return NULL;
            }

            pthread_mutex_unlock(&data->death_mutex);
            i++;
        }
        usleep(1000); // 1ms pause to avoid busy wait
    }
    return NULL;
}
