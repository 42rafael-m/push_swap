#include "push_swap.h"

void    *ft_copy_content(void *content)
{
    int     *copy;

    copy = (int *)ft_calloc(1, sizeof(int));
    if (!copy)
        return (NULL);
    *copy = *(int *)content;
    	return ((void *)copy);
}

void	ft_few_args(t_list **stack)
{
	if (ft_lstsize(*stack) == 4)
		ft_sort_four(stack);
	ft_sort_three(stack);
	ft_lstiter(*stack, ft_print_content);
	return ;
}

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

void	ft_sort_four(t_list **stack)
{
	int	min;

	min = ft_find_min(*stack);
	if (*(int *)(*stack) -> next -> next -> next -> content == min)
		ft_rev_rot_a(stack);
	else
		while (*(int *)(*stack) -> content != min)
			ft_rotate_a(stack);
	if (ft_is_sorted(*stack))
		return ;
	min = ft_find_min((*stack) -> next);
	while (*(int *)(*stack) -> next -> content != min)
	{
		ft_rev_rot_a(stack);
		ft_swap_a(stack);
	}
	if (ft_is_sorted(*stack))
		return ;
	ft_rotate_a(stack);
	ft_rotate_a(stack);
	ft_swap_a(stack);
	ft_rotate_a(stack);
	ft_rotate_a(stack);
	return ;
}


