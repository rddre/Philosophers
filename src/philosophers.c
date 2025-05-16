



#include "../philo.h"

void	init_data(t_data *data, char **av, int nb_arg)
{
	data->nb_philo = ft_atoi(av[1]);
	data->life_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);

	if (nb_arg == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
}

int	main(int nb_arg, char **av)
{
	t_data data;

	if (nb_arg != 5 && nb_arg != 6)
		return (print("Erreur : mauvais nombre d'argument\n"), 1);

	parsing( nb_arg, av);

	init_data(&data, av, nb_arg);

	print_action(data.nb_philo, " le nombre de philosopher\n");
	print_action(data.life_time, " dure de vie des philosopher\n");
	print_action(data.eat_time, " temp qu'il leur faut pour manger\n");
	print_action(data.sleep_time, " temps qu'il faut pour dormir\n");
	print_action(data.must_eat, " le nombre de repas qu'il doivent prendre\n");
	return (1);
}
