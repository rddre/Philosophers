#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int	nb_philo;
	int	life_time;
	int eat_time;
	int	sleep_time;
} t_data;

/*       parsing       */
int		parsing(char **av);

/*         utils          */
size_t	ft_strlen(const char *str);
int		print(char *s);
void	ft_putnbr(int n);
int		print_action(int nb, char *s);

#endif