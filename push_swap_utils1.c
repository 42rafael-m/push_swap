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
	if (!(*stack) -> next -> next)
		return ;
	a = *(int *)(*stack) -> content;
	b = *(int *)(*stack) -> next -> content;
    c = *(int *)(*stack) -> next -> next -> content;
	if (b > c)
	{
		if (c < a)
			return (ft_rev_rot_a(stack));
		else
		{
			ft_rotate_a(stack);
			ft_swap_a(stack);
			// ft_rev_rot_a(stack);
		}
	}
    return ;
}