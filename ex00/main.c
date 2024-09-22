#include <unistd.h>
#include <stdlib.h>

int	ft_check_input(int argc, char **argv, char **dict, char **number)
{
	char	*temp;

	if (argc < 2 || argc > 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (argc == 3)
	{
		*dict = argv[1];
		*number = argv[2];
	}
	else
	{
		*dict = "numbers.dict";
		*number = argv[1];
	}
	temp = *number;
	while (*temp)
	{
		if (*temp < '0' || *temp > '9')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		temp++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*dict;
	char	*number;

	if (ft_check_input(argc, argv, &dict, &number))
	{
		if (!dict)
		{
			write(2, "Dict Error\n", 11);
			return (0);
		}
		//Convert number and parse dict...
	}
	return (0);
}
