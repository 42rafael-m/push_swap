NAME = push_swap
LIBFT_A = libft/libft.a
SRC = push_swap.c push_swap_utils.c push_swap_utils1.c push_swap_utils2.c
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Wextra -Werror -Ilibft

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	$(MAKE) bonus -C libft

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm  -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re NAME