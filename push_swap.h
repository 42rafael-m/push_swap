#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>

char	**ft_swap(char	**stack_a);
size_t	ft_dptr_len(char **dptr);
char	**ft_push(char **stack_a, char **stack_b);
char	**ft_rev_rot(char **stack);
char	**ft_rotate(char **stack);

#endif