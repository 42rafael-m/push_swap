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
    {
	    ft_swap_s(stack);
	    write(1, "sa\n", 3);
	    return ;
    }
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
		{
			ft_rev_rot(stack);
			write(1, "rra\n", 4);
			return ;
		}
		ft_rotate(stack);
		write(1, "ra\n", 3);
		ft_swap_s(stack);
		write(1, "sa\n", 3);
		ft_rev_rot(stack);
		write(1, "rra\n", 4);
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
			return (write(1, "rra\n", 4), ft_rev_rot(stack));
		if (d < b)
		{
			write(1, "rra\n", 4);
			write(1, "sa\n", 3);
			return (ft_rev_rot(stack), ft_swap_s(stack));
		}
		write(1, "rra\n", 4);
		write(1, "sa\n", 3);
		return (ft_rev_rot(stack), ft_swap_s(stack));
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