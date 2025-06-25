#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

#include <stdio.h>

# define INV_CHARS " !\"#$%&'()*./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]\
^_`abcdefghijklmnopqrstuvwxyz{|}~"

void    ft_swap_s(t_list **stack_a, t_list **stack_b);
void    ft_push_a(t_list **stack_a, t_list **stack_b);
void    ft_rev_rot_r(t_list **stack, t_list **stack_b);
void    ft_rotate_a(t_list **stack);
int     ft_push_swap(t_list **stack_a, t_list **stack_b);
void	*ft_copy_content(void *content);
t_list	*ft_quickshort(t_list *list);
int	    ft_choose_pivot(t_list *list);
t_list	*ft_load_stackn(int size);
void    ft_sort_two(t_list **stack);
void	ft_few_args(t_list **stack);
t_list	*ft_quickshort(t_list *list);
t_list	*ft_sort(t_list	*list, int pivot);
int	    ft_choose_pivot(t_list *list);
void	*ft_copy_content(void *content);
void    ft_sort_three(t_list **stack);
int	    ft_is_sorted(t_list *stack);
void	ft_sort_four(t_list **stack);
void    ft_print_content(void *s);
void	ft_four(t_list **stack);
int	    ft_find_pos_e(t_list **stack);
int     ft_choose_operation(t_list *stack);
void    ft_sort_stack_a(t_list **stack);
t_list  *ft_stack_a(int argc, char **argv);
void	ft_rev_sort_a(t_list **list, int op);
t_list  *ft_stack_b(int argc, char **argv);
void	ft_rev_sort_b(t_list **list, int op);
void	ft_rotate_r(t_list **stack_a, t_list **stack_b);
void	ft_rotate_b(t_list **stack);
void	ft_rev_rot_b(t_list **stack);
void	ft_rev_rot_a(t_list **stack);
void	ft_push_b(t_list **stack_b, t_list **stack_a);
void	ft_swap_b(t_list **stack);
void	ft_swap_a(t_list **stack);

#endif