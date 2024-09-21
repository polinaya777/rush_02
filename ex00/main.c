#include <unistd.h>
#include <stdlib.h>
#include "ft_parse_dict.h"
#include "ft_atoi.h"

int	main(int argc, char **argv[])
{
	int	i;
	char	*dict;
	char	*number;

	if (argc < 2 || argc > 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
    if (argc == 3)
	{
		dict = argv[1];
		number = argv[2];
	}
	else
	{
		dict = "numbers.dict";
		number == argv[1];
	}
	i = 0;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	if (!dict)
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	
	//Convert number and parse dict...
	
	return (0);
}

