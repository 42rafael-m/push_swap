/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:59:09 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/20 21:03:43 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_max(t_list *list)
{
	t_list	*r;
	int		max;

	max = INT_MIN;
	if (!list)
		return (NULL);
	r = list;
	while (list)
	{
		if (*(int *)list -> content > max)
		{
			r = list;
			max = *(int *)list -> content;
		}
		list = list -> next;
	}
	return (r);
}

t_list	*ft_find_min(t_list *list)
{
	t_list	*r;
	int		min;

	if (!list)
		return (NULL);
	r = list;
	min = INT_MAX;
	while (list)
	{
		if (*(int *)list -> content < min)
		{
			r = list;
			min = *(int *)list -> content;
		}
		list = list -> next;
	}
	return (r);
}

t_list	*ft_choose_target_b(t_list **stack_b, t_list **stack_a, unsigned int t)
{
	int		cost_a;
	int		cost_b;
	t_list	*target;
	t_list	*node;

	target = NULL;
	node = *stack_b;
	while (node)
	{
		if (t <= (ft_abs(ft_choose_op(*stack_a, ft_find_node_target_b(node,
							*stack_a))) + ft_abs(ft_choose_op(*stack_b, node))))
		{
			node = node -> next;
			continue ;
		}
		target = ft_find_node_target_b(node, *stack_a);
		if (!target)
			return (NULL);
		cost_a = ft_choose_op(*stack_a, target);
		cost_b = ft_choose_op(*stack_b, node);
		t = ft_abs(cost_a) + ft_abs(cost_b);
		node = node -> next;
	}
	ft_rot_cost(cost_a, cost_b, stack_a, stack_b);
	return (target);
}

t_list	*ft_choose_target_a(t_list **stack_a, t_list **stack_b, unsigned int t)
{
	int		cost_a;
	int		cost_b;
	t_list	*target;
	t_list	*node;

	target = NULL;
	node = *stack_a;
	while (node)
	{
		if (t <= (ft_abs(ft_choose_op(*stack_b, ft_find_node_target_a(node,
							*stack_a))) + ft_abs(ft_choose_op(*stack_a, node))))
		{
			node = node -> next;
			continue ;
		}
		t = ft_abs(cost_a) + ft_abs(cost_b);
		target = ft_find_node_target_a(*stack_a, node);
		if (!target)
			return (NULL);
		cost_a = ft_choose_op(*stack_b, ft_find_node_target_a(node, *stack_a));
		cost_b = ft_choose_op(*stack_a, node);
		node = node -> next;
	}
	ft_rot_cost(cost_a, cost_b, stack_a, stack_b);
	return (target);
}

int	ft_rot_cos(int cost_a, int cost_b, t_list **stack_a, t_list **stack_b)
{
	if (cost_b > 0)
		while (cost_b-- > 0)
			ft_rotate_b(stack_b);
	else if (cost_b < 0)
		while (cost_b++ < 0)
			ft_rev_rot_b(stack_b);
	if (cost_a < 0)
		while (cost_a++ < 0)
			ft_rev_rot_a(stack_a);
	else if (cost_a > 0)
		while (cost_a-- > 0)
			ft_rotate_a(stack_a);
	return (0);
}
