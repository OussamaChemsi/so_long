CC = cc
CFLAGS = -Wall -Wextra -Werror

GET_NEXT_LINE = includes/get_next_line


SRC = so_long.c  $(GET_NEXT_LINE)/get_next_line.c $(GET_NEXT_LINE)/get_next_line_utils.c ft_strstr.c

OBJ	= $(SRC:.c=.o)

NAME = so_long

all :

	$(CC) $(CFLAGS) flood_fill.c ft_split.c utils_split.c so_long.c check_pce.c check_map.c $(GET_NEXT_LINE)/get_next_line.c $(GET_NEXT_LINE)/get_next_line_utils.c ft_strstr.c  -o $(NAME) -fsanitize=address -g

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
