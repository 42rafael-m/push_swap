/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:39:56 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/21 14:35:14 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_copy_content(void *content)
{
	int	*copy;

	copy = (int *)ft_calloc(1, sizeof(int));
	if (!copy)
		return (NULL);
	*copy = *(int *)content;
	return ((void *)copy);
}

void	ft_sort_two(t_list **stack)
{
	int	a;
	int	b;

	if (!(*stack) || !(*stack)-> next)
		return ;
	a = *(int *)(*stack)-> content;
	b = *(int *)(*stack)-> next -> content;
	if (a < b)
		return ;
	if (a > b)
		return (ft_swap_a(stack));
	return ;
}

void	ft_sort_three(t_list **stack)
{
	int	b;
	int	c;
	int	a;

	if (!(*stack) || !(*stack)-> next || ft_is_sorted(*stack))
		return ;
	ft_sort_two(stack);
	if (!(*stack)-> next -> next)
		return ;
	a = *(int *)(*stack)-> content;
	b = *(int *)(*stack)-> next -> content;
	c = *(int *)(*stack)-> next -> next -> content;
	if (b > c)
	{
		if (c < a)
			return (ft_rev_rot_a(stack));
		else
		{
			ft_rotate_a(stack);
			ft_swap_a(stack);
		}
	}
	return ;
}

int	ft_rot_cost(int cost_a, int cost_b, t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || ! stack_b || !*stack_a || !*stack_b)
		return (1);
	if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			ft_rotate_r(stack_a, stack_b);
			cost_a--;
			cost_b--;
		}
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			ft_rev_rot_r(stack_a, stack_b);
			cost_a++;
			cost_b++;
		}
	}
	ft_rot_cos(cost_a, cost_b, stack_a, stack_b);
	return (0);
}

int	ft_push_swap_a(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a)
		return (1);
	if (ft_is_sorted(*stack_a))
		return (ft_lstclear(stack_b, free), stack_b = NULL, 0);
	while (ft_lstsize(*stack_a) > 3)
	{
		ft_choose_target_a(stack_a, stack_b, INT_MAX);
		ft_push_b(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	return (0);
}
