#ifndef DICT_PARSE_H
# define DICT_PARSE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict_entry
{
	long	number;
	char	*word;
}	t_dict_entry;

t_dict_entry	*ft_parse_dict(char *dict);
long			ft_atol(char *str);
char			**ft_split(char *str, char *charset);
char			*ft_strtrim(char *str, char *charset);

#endif
