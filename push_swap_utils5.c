/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:43:03 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/21 13:47:30 by rafael-m         ###   ########.fr       */
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

int	ft_rep_content(t_list *stack)
{
	t_list	*start;
	int		content;

	if (!stack)
		return (0);
	content = *(int *)stack->content;
	start = stack;
	while (stack)
	{
		stack = stack->next;
		if (stack && content == *(int *)stack->content)
			return (1);
	}
	start = start->next;
	if (!start)
		return (0);
	if (ft_rep_content(start))
		return (1);
	return (0);
}

