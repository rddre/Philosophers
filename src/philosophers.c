



#include "../philo.h"

int	main(int nb_arg, char **av)
{
	t_data data;

	if (nb_arg != 5 && nb_arg != 6)
		return (print("Erreur : mauvais nombre d'argument"), 1);

	parsing(av);

	return (1);
}