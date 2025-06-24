#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

#include <stdio.h>

# define INV_CHARS " !\"#$%&'()*./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]\
^_`abcdefghijklmnopqrstuvwxyz{|}~"

void    ft_swap_s(t_list    **stack_a);
void    ft_push(t_list **stack_a, t_list **stack_b);
void    ft_rev_rot(t_list **stack);
void    ft_rotate(t_list **stack);
int     ft_push_swap(t_list **stack_a, t_list **stack_b);
void	*ft_copy_content(void *content);
t_list	*ft_quickshort(t_list *list);
int	    ft_choose_pivot(t_list *list);
t_list	*ft_load_stackn(int size);
void    ft_sort_two(t_list **stack);
void	ft_few_args(int argc, t_list **stack);
t_list	*ft_quickshort(t_list *list);
t_list	*ft_sort(t_list	*list, int pivot);
int	    ft_choose_pivot(t_list *list);
void	*ft_copy_content(void *content);
void    ft_sort_three(t_list **stack, int *argc);
int	    ft_is_sorted(t_list *stack);
void	ft_sort_four(t_list **stack, int *argc);
void    ft_print_content(void *s);

#endif