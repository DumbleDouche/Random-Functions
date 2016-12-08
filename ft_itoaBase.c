#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

size_t		ft_digits(long nbr, unsigned int base)
{
	size_t	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

long long	ft_atoi(char *str)
{
	bool	isneg = 0;
	long 	res = 0;

	while (*str == '\t' || *str == '\n' || *str == '\r'
	|| *str == '\v' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isneg = 1;
		str++;
	}
	if (!*str || !(*str >= 48 && *str <= 57))
	{
		write(1, "Bad input\n", 10);
		exit (-1);
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		res *= 10;
		res += (int)*str - 48;
		str++;
	}
	(isneg) ? (res *= -1) : res;
	return (res);
}

char		*ft_itoaBase(long nbr, unsigned int base)
{
	long 	n = 0;
	char	sample[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char	*ret;
	size_t	digits = ft_digits(nbr, base);

	ret = (char *)malloc(sizeof(char) * (digits));
	ret[digits] = '\0';
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr *= -1;
	}
	digits--;
	while (nbr)
	{
		n = nbr;
		if (n >= base)
			n = nbr % base;
		ret[digits] = sample[n];
		nbr /= base;
		digits--;
	}
	return (ret);
}

int			main(int argc, char **argv)
{
	switch (argc)
	{
		case 1:
			write(1, "Missing number\n", 15);
		case 2:
			write(1, "Missing base\n", 13);
			return (1);
	}
	long base = ft_atoi(argv[2]);
	long nbr = ft_atoi(argv[1]);
	printf("%s\n", (ft_itoaBase(nbr, base)));
	return (0);
}
