/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:39:44 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/20 21:44:23 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **stack)
{
	t_list	*node;

	if (!*stack || !(*stack)-> next)
		return ;
	node = (*stack)-> next;
	(*stack)-> next = node -> next;
	node -> next = *stack;
	*stack = node;
	write(1, "sa\n", 3);
	return ;
}

void	ft_swap_b(t_list **stack)
{
	t_list	*node;

	if (!*stack || !(*stack)-> next)
		return ;
	node = (*stack)-> next;
	(*stack)-> next = node -> next;
	node -> next = *stack;
	*stack = node;
	write(1, "sb\n", 3);
	return ;
}

void	ft_swap_s(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	if (!*stack_a || !(*stack_a)-> next || !*stack_b || !(*stack_b)-> next)
		return ;
	node = (*stack_a)-> next;
	(*stack_a)-> next = node -> next;
	node -> next = *stack_a;
	*stack_a = node;
	node = (*stack_b)-> next;
	(*stack_b)-> next = node -> next;
	node -> next = *stack_b;
	*stack_b = node;
	write(1, "ss\n", 3);
	return ;
}

void	ft_push_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*t;

	if (!*stack_b)
		return ;
	t = *stack_b;
	*stack_b = t -> next;
	t -> next = *stack_a;
	*stack_a = t;
	write(1, "pb\n", 3);
	return ;
}

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*t;

	if (!*stack_a)
		return ;
	t = *stack_a;
	*stack_a = t -> next;
	t -> next = *stack_b;
	*stack_b = t;
	write(1, "pa\n", 3);
	return ;
}
