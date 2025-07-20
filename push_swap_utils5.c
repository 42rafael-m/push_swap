/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:43:03 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/20 21:47:28 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rot_a(t_list **stack)
{
	t_list	*last;
	t_list	*node;

	if (!*stack || !(*stack)-> next)
		return ;
	node = *stack;
	while (node && node -> next && (node -> next)-> next)
		node = node -> next;
	last = node -> next;
	node -> next = NULL;
	last -> next = *stack;
	*stack = last;
	write(1, "rra\n", 4);
	return ;
}

void	ft_rev_rot_b(t_list **stack)
{
	t_list	*last;
	t_list	*node;

	if (!*stack || !(*stack)-> next)
		return ;
	node = *stack;
	while (node && node -> next && (node -> next)-> next)
		node = node -> next;
	last = node -> next;
	node -> next = NULL;
	last -> next = *stack;
	*stack = last;
	write(1, "rrb\n", 4);
	return ;
}
