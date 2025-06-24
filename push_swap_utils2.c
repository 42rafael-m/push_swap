#include "push_swap.h"

void    ft_sort_two(t_list **stack)
{
    int	a;
	int b;

	if ((*stack))
		a = *(int *)(*stack) -> content;
	if ((*stack) -> next)
		b = *(int *)(*stack) -> next -> content;
    if (a < b)
		return ;
	if (a > b)
    {
	    ft_swap_s(stack);
	    write(1, "sa\n", 3);
	    return ;
    }
}

void    ft_sort_three(t_list **stack, int *argc)
{
	int b;
	int c;

	if (!(*stack) || !(*stack) -> next || !(*stack) -> next -> next)
		return ;
	if ((*stack) -> next)
		b = *(int *)(*stack) -> next -> content;
	if ((*stack) -> next -> next)
    	c = *(int *)(*stack) -> next -> next -> content;
    ft_sort_two(stack);
	if (b > c)
	{
		ft_rotate(stack);
		write(1, "ra\n", 3);
		ft_swap_s(stack);
		write(1, "sa\n", 3);
		ft_rev_rot(stack);
		write(1, "rra\n", 4);
		(*argc)--;
	}
    return ;
}

// void	ft_sort_four(t_list *stack, int *argc)
// {
// 	int a;
// 	int b;
// 	int	c;
// 	int	d;

// 	if (ft_lstsize < 4)
// 		return ;
// 	a = *(int *)stack -> content;
// 	b = *(int *)stack -> next -> content;
// 	c = *(int *)stack -> next -> next -> content;
// 	d = *(int *)stack -> next -> next -> next -> content;
// 	ft_sort_three(stack, argc);
// 	if (c > d)
// 	{
// 		ft_rotate(stack);
// 		write(1, "ra\n", 3);
// 		ft_rotate(stack);
// 		write(1, "ra\n", 3);
// 		ft_swap_s(&stack);
// 		write(1, "sa\n", 3);
// 		ft_rev_rot(stack);
// 		write(1, "rra\n", 4);
// 		ft_rev_rot(stack);
// 		write(1, "rra\n", 4);
// 	}
// }

int	ft_is_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack && stack -> next)
	{
		if (stack -> content > stack -> next -> content)
			return (0);
		stack = stack -> next;
	}
	return (1);
}