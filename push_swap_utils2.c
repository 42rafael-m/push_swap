#include "push_swap.h"

void    ft_sort_two(t_list **stack)
{
    int	a;
	int b;

	if (!(*stack) || !(*stack) -> next)
		return ;
	a = *(int *)(*stack) -> content;
	b = *(int *)(*stack) -> next -> content;
    if (a < b)
		return ;
	if (a > b)
	    return (ft_swap_a(stack));
	return ;
}

void    ft_sort_three(t_list **stack)
{
	int b;
	int c;
	int	a;

	if (!(*stack) || !(*stack) -> next || !(*stack) -> next -> next)
		return ;
    ft_sort_two(stack);
	a = *(int *)(*stack) -> content;
	b = *(int *)(*stack) -> next -> content;
    c = *(int *)(*stack) -> next -> next -> content;
	if (b > c)
	{
		if (c < a)
			return (ft_rev_rot_a(stack));
		ft_rotate_a(stack);
		ft_swap_a(stack);
		ft_rev_rot_a(stack);
	}
    return ;
}

void	ft_four(t_list **stack)
{
	int a;
	int b;
	int	c;
	int	d;

	a = *(int *)(*stack) -> content;
	b = *(int *)(*stack) -> next -> content;
	c = *(int *)(*stack) -> next -> next -> content;
	d = *(int *)(*stack) -> next -> next -> next -> content;
	if (c > d)
	{
		if (d < a)
			return (ft_rev_rot_a(stack));
		if (d < b)
			return (ft_rev_rot_a(stack), ft_swap_a(stack));
		return (ft_rev_rot_a(stack), ft_swap_a(stack));
	}
}

void	ft_sort_four(t_list **stack)
{
	t_list	*t;


	if (ft_lstsize(*stack) < 4)
		return ;
	t = (*stack) -> next -> next -> next;
	(*stack) -> next -> next -> next = NULL;
	ft_sort_three(stack);
	(*stack) -> next -> next -> next = t;
	if (ft_is_sorted(*stack))
		return ;
	ft_four(stack);
	return ;
}

int	ft_is_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack && stack -> next)
	{
		if (*(int *)stack -> content > *(int *)stack -> next -> content)
			return (0);
		stack = stack -> next;
	}
	return (1);
}