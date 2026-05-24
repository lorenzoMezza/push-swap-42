NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  ft_list.c \
		  ft_array.c \
		  ft_checks.c \
		  ft_compare.c \
		  ft_convert.c \
		  ft_execute.c \
		  ft_fastest.c \
		  ft_find.c \
		  ft_find_spot_b.c \
		  ft_find_spot_a.c \
		  ft_free.c \
		  ft_position.c \
		  ft_push.c \
		  ft_rotate.c \
		  ft_reverse_rotate.c \
		  ft_sort_small.c \
		  ft_sort_big.c \
		  ft_swap.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
