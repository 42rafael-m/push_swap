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

	if (!(*stack) || !(*stack) -> next)
		return ;
    ft_sort_two(stack);
	if ( !(*stack) -> next -> next)
		return ;
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
	while ((*stack) -> content != ft_find_min(*stack))
		ft_rotate_a(stack);
		
}

void	ft_sort_four(t_list **stack)
{
	// t_list	*t;

	if (ft_lstsize(*stack) < 4)
		return (ft_sort_three(stack));
	// t = (*stack) -> next -> next -> next;
	// (*stack) -> next -> next -> next = NULL;
	// (*stack) -> next -> next -> next = t;
	if (ft_is_sorted(*stack))
		return ;
	ft_four(stack);
	return ;
}

