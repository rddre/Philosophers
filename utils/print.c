#include "../push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

int	print(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	print_action(int nb, char *s)
{
    ft_putnbr(nb);
	return (write(1, s, ft_strlen(s)));
}

int	print_exit(char *s)
{
	print(s);
	exit(1);
}
