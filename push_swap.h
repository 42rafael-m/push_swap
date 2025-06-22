#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

# define INV_CHARS " !\"#$%&'()*./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]\
^_`abcdefghijklmnopqrstuvwxyz{|}~"

void    ft_swap_s(t_list    **stack_a);
void    ft_push(t_list **stack_a, t_list **stack_b);
void    ft_rev_rot(t_list **stack);
void    ft_rotate(t_list **stack);
int     ft_push_swap(t_list **stack_a, t_list **stack_b, int argc);

#endif