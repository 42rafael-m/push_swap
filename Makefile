NAME = push_swap
LIBFT_A = libft/libft.a
SRC = push_swap.c push_swap_utils.c
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	make -C libft

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm  -f $(OBJ) libft.a
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re NAME