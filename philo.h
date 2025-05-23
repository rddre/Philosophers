#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_data
{
	int	nb_philo;
	int	life_time;
	int eat_time;
	int	sleep_time;

	int must_eat;

	pthread_mutex_t	*forks;

	long long time;
	int dead;
	pthread_mutex_t death_mutex;
} t_data;

typedef struct s_philo
{
	int         id;
	int         meals_eaten;
	long long   last_meal_time;
	pthread_t   thread;

	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;

	t_data      *data;
}	t_philo;

/*      philo et routine     */
void	philo(t_data *data);
long long timestamp_ms(long long time);

/*       parsing       */
int		parsing(int nb_arg, char **av);

/*         utils          */
size_t	ft_strlen(const char *str);
int		print(char *s);
void	ft_putnbr(int n);
int		print_action(int nb, char *s);
void	print_exit(char *s);
int		ft_atoi(const char *str);

/*            exit           */
void	exit_free(t_data *data, t_philo *philos, int code);

#endif