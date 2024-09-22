NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c ft_atol.c ft_split.c ft_strtrim.c ft_parse_dict.c???
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
