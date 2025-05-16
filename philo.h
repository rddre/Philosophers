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
} t_data;

/*       parsing       */
int		parsing(int nb_arg, char **av);

/*         utils          */
size_t	ft_strlen(const char *str);
int		print(char *s);
void	ft_putnbr(int n);
int		print_action(int nb, char *s);
void	print_exit(char *s);
int		ft_atoi(const char *str);

#endif