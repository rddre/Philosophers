#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


/*         utils          */
size_t	ft_strlen(const char *str);
int		print(char *s);
void	ft_putnbr(int n);
int		print_action(int nb, char *s);

#endif