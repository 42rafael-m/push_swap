/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:40:14 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/20 20:18:06 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_node_target_b(t_list *node, t_list *stack)
{
	t_list	*r;
	t_list	*start;
	int		closest;
	int		content;
	int		content_a;

	if (!node || !stack)
		return (NULL);
	closest = INT_MAX;
	content = *(int *)node -> content;
	r = NULL;
	start = stack;
	while (stack)
	{
		content_a = *(int *)stack -> content;
		if (content_a > content && content_a < closest)
		{
			r = stack;
			closest = content_a;
		}
		stack = stack -> next;
	}
	if (!r)
		r = ft_find_min(start);
	return (r);
}

t_list	*ft_find_node_target_a(t_list *node, t_list *stack)
{
	t_list	*r;
	int		closest;
	int		content;
	int		content_b;

	if (!node || !stack)
		return (NULL);
	closest = INT_MIN;
	content = *(int *)node -> content;
	r = stack;
	while (stack)
	{
		content_b = *(int *)stack -> content;
		if (content_b < content && content_b > closest)
		{
			r = stack;
			closest = content_b;
		}
		stack = stack -> next;
	}
	if (!r)
		r = ft_find_max(stack);
	return (r);
}

t_list	*ft_find_b_target(t_list *node, t_list *stack)
{
	t_list	*r;
	int		closest;
	int		content;
	int		content_a;

	if (!node || !stack)
		return (NULL);
	closest = INT_MAX;
	content = *(int *)node -> content;
	r = NULL;
	while (stack)
	{
		content_a = *(int *)stack -> content;
		if (content_a < content && content_a < closest)
		{
			r = stack;
			closest = content_a;
		}
		stack = stack -> next;
	}
	return (r);
}

int	ft_choose_op(t_list *stack, t_list *node)
{
	int	size;
	int	pos;

	if (!stack)
		return (INT_MIN);
	pos = 0;
	size = ft_lstsize(stack);
	while (stack)
	{
		if (*(int *)stack -> content == *(int *)node -> content)
			break ;
		pos++;
		stack = stack -> next;
	}
	if (pos <= (size / 2))
		return (pos);
	pos = size - pos;
	return (-pos);
}
