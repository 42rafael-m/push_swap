/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:40:29 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/21 12:56:51 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

# define INV_CHARS " !\"#$%&'()*./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]\
^_`abcdefghijklmnopqrstuvwxyz{|}~"

int		ft_push_swap(t_list **stack_a, t_list **stack_b, int count);
int		ft_is_sorted(t_list *stack);
int		ft_is_rev_sorted(t_list *stack);
int		ft_choose_op(t_list *stack, t_list *node);
int		ft_push_swap_a(t_list **stack_a, t_list **stack_b);
int		ft_push_swap_b(t_list **stack_a, t_list **stack_b);
int		ft_rot_cost(int cost_a, int cost_b, t_list **stack_a, t_list **stack_b);
int		ft_rot_cos(int cost_a, int cost_b, t_list **stack_a, t_list **stack_b);
int		ft_rep_content(t_list *stack);
void	*ft_copy_content(void *content);
void	ft_sort_two(t_list **stack);
void	ft_few_args(t_list **stack);
void	ft_sort_three(t_list **stack);
void	ft_sort_four(t_list **stack);
void	ft_print_content(void *s);
void	ft_rotate_r(t_list **stack_a, t_list **stack_b);
void	ft_rotate_b(t_list **stack);
void	ft_rev_rot_b(t_list **stack);
void	ft_rev_rot_a(t_list **stack);
void	ft_push_b(t_list **stack_b, t_list **stack_a);
void	ft_swap_b(t_list **stack);
void	ft_swap_a(t_list **stack);
void	ft_swap_s(t_list **stack_a, t_list **stack_b);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_rev_rot_r(t_list **stack, t_list **stack_b);
void	ft_rotate_a(t_list **stack);
t_list	*ft_stack_a(int argc, char **argv);
t_list	*ft_find_max(t_list *list);
t_list	*ft_find_min(t_list *list);
t_list	*ft_find_node_target_a(t_list *node, t_list *stack);
t_list	*ft_find_node_target_b(t_list *node, t_list *stack);
t_list	*ft_choose_target_a(t_list **stack_a, t_list **stack_b, unsigned int t);
t_list	*ft_choose_target_b(t_list **stack_b, t_list **stack_a, unsigned int t);
t_list	*ft_load_stck_a(int *argc, char **argv);

#endif
