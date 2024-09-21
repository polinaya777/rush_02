#include <unistd.h>
#include <stdlib.h>

typedef struct	s_dict_entry
{
	char *number;
	char *word;
}	t_dict_entry;

t_dict_entry	*parse_dict(char *dict)
{
	int				fd;
	t_dict_entry	*new_dict;

	fd = open(dict, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Dict Error\n", 11);
		return NULL;
	}

	new_dict = NULL;
	//Convert dict to new struct or ???

    close(fd);
	return (new_dict);
}
