/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:07:38 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/20 21:41:15 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_swap_b(t_list **stack_a, t_list **stack_b)
{
	int	op;

	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return (1);
	op = 0;
	while (ft_lstsize(*stack_b) > 0)
	{
		ft_choose_target_b(stack_b, stack_a, INT_MAX);
		ft_push_a(stack_b, stack_a);
	}
	op = ft_choose_op(*stack_a, ft_find_min(*stack_a));
	ft_rot_cost(op, 0, stack_a, stack_a);
	return (0);
}

void	ft_rotate_a(t_list **stack)
{
	t_list	*t;
	t_list	*start;

	if (!*stack || !(*stack)-> next)
		return ;
	start = *stack;
	*stack = start -> next;
	t = ft_lstlast(*stack);
	t -> next = start;
	start -> next = NULL;
	write(1, "ra\n", 4);
	return ;
}

void	ft_rotate_b(t_list **stack)
{
	t_list	*t;
	t_list	*start;

	if (!*stack || !(*stack)-> next)
		return ;
	start = *stack;
	*stack = start -> next;
	t = ft_lstlast(*stack);
	t -> next = start;
	start -> next = NULL;
	write(1, "rb\n", 4);
	return ;
}

void	ft_rotate_r(t_list **stack_a, t_list **stack_b)
{
	t_list	*t;
	t_list	*start;

	if (!*stack_a || !(*stack_a)-> next || !*stack_b || !(*stack_b)-> next)
		return ;
	start = *stack_a;
	*stack_a = start -> next;
	t = ft_lstlast(*stack_a);
	t -> next = start;
	start -> next = NULL;
	start = *stack_b;
	*stack_b = start -> next;
	t = ft_lstlast(*stack_b);
	t -> next = start;
	start -> next = NULL;
	write(1, "rr\n", 4);
	return ;
}

void	ft_rev_rot_r(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*node;

	if (!*stack_a || !(*stack_a)-> next || !*stack_b || !(*stack_b)-> next)
		return ;
	node = *stack_a;
	while (node && node -> next && (node -> next)-> next)
		node = node -> next;
	last = node -> next;
	node -> next = NULL;
	last -> next = *stack_a;
	*stack_a = last;
	node = *stack_b;
	while (node && node -> next && (node -> next)-> next)
		node = node -> next;
	last = node -> next;
	node -> next = NULL;
	last -> next = *stack_b;
	*stack_b = last;
	write(1, "rrr\n", 4);
	return ;
}
