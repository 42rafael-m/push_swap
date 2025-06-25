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
	if (pos_e < pos_h)
		return (-pos_e);
	return (pos_h);
}

void	ft_rev_sort(t_list **stack, int op)
{
	if (!stack || !*stack)
		return ;
	while (op >= )
	{
		ft_rotate(stack);
		write(1, "ra\n", 3);
		op--;
		ft_swap_s();
	}
}

void    ft_sort_stack(t_list **stack)
{
	int	op;

    if (!stack || !*stack)
        return ;
	while (stack)
	{
		op = ft_choose_operation(*stack);
		if (op < 0)
		{
			op = -op;
		
		}
	}
}