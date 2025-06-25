#include "push_swap.h"

int	ft_find_pos_e(t_list **stack)
{
	int	pos_e;
	int	i;
	t_list  *head;

	head = *stack;
	pos_e = ft_lstsize(*stack) - 1;
	*stack = ft_lstlast(*stack);
	i = 0;
	while (pos_e > 0)
	{

		if (*(int *)head -> content > *(int *)(*stack) -> content || !(*stack))
			break ;
		*stack = head;
		pos_e--;
		i = 0;
		while (i < pos_e)
		{
			*stack = (*stack) -> next;
			i++;
		}
	}
	return (ft_lstsize(head) - pos_e);
}

int	ft_choose_operation(t_list *stack)
{
	t_list  *head;
	int	pos_h;
	int	pos_e;

    if (!stack)
        return (-1);
    head = stack;
	pos_h = 0;
	stack = stack -> next;
    while (stack)
    {
        if (*(int *)head -> content < *(int *)stack -> content)
            break ;
        stack = stack -> next;
		pos_h++;
    }
	pos_e = ft_find_pos_e(&head);
	printf("pos_e = %d\n", pos_e);
	printf("pos_h = %d\n", pos_h);
	if (pos_e < pos_h)
		return (-pos_e);
	return (pos_h);
}

void	ft_rev_sort_a(t_list **stack, int op)
{
	if (!stack || !*stack)
		return ;
	while (op > 0)
	{
		ft_rotate_a(stack);
		op--;
	}
	ft_swap_a(stack);
	return ;
}

void    ft_sort_stack_a(t_list **stack)
{
	int	op;

    if (!stack || !*stack)
        return ;
	if (ft_is_sorted(*stack))
		return ;
	op = ft_choose_operation(*stack);
	printf ("op = %d\n", op);
	if (op < 0)
	{
		while (op < 0)
		{
			ft_rev_rot_a(stack);
			ft_swap_a(stack);
			op++;
		}
	}
	if (op > 0)
	{
		while (op > 1)
		{
			ft_swap_a(stack);
			ft_rotate_a(stack);
			op--;
		}
		ft_swap_a(stack);
	}
	ft_lstiter(*stack, ft_print_content);
	printf("\n");
	if (ft_is_sorted(*stack))
		return ;
	ft_rotate_a(stack);
	ft_sort_stack_a(stack);
}