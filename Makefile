
CC = cc
CFLAGS = -Wall -Wextra -Werror

GET_NEXT_LINE = includes/get_next_line

# SRC = $(wildcard *.c)
SRC = check_map.c check_pce.c flood_fill.c so_long.c utils.c $(GET_NEXT_LINE)/get_next_line.c   $(GET_NEXT_LINE)/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
LINK = -lXext -lX11 -lmlx

NAME = so_long

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re : fclean all


