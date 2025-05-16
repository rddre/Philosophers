


#include "../../philo.h"


int	ft_isdigit(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' && s[i] > '9')
			print_exit("Erreur : caractere non conforme\n");
		i++;
	}
	return (0);
}

int parsing(int nb_arg, char **av)
{
	ft_isdigit(av[1]);
	ft_isdigit(av[2]);
	ft_isdigit(av[3]);
	ft_isdigit(av[4]);
	if (nb_arg == 6)
	{
		ft_isdigit(av[5]);
		if (ft_atoi(av[5]) < 1 || ft_atoi(av[5]) > INT_MAX)
        	print_exit("Erreur : valeur hors limite\n");
	}

	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 300)
		print_exit("Erreur : nombre de philosophe non conforme\n");
	if (ft_atoi(av[2]) < 1 || ft_atoi(av[2]) > INT_MAX)
        print_exit("Erreur : valeur hors limite\n");
	if (ft_atoi(av[3]) < 1 || ft_atoi(av[3]) > INT_MAX)
        print_exit("Erreur : valeur hors limite\n");
	if (ft_atoi(av[4]) < 1 || ft_atoi(av[4]) > INT_MAX)
        print_exit("Erreur : valeur hors limite\n");
	
	return (0);
}
