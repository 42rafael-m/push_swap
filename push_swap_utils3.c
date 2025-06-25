#include "push_swap.h"

int	ft_find_pos_e(t_list **stack)
{
	int	pos_e;
	int	i;
	t_list  *head;

	// printf("p = %p, c = %d\n", *stack, *(int *)(*stack) -> content);
	head = *stack;
	pos_e = ft_lstsize(*stack);
	*stack = ft_lstlast(*stack);
	// printf("pl = %p, cl = %d\n", *stack, *(int *)(*stack) -> content);
	i = 0;
	while (pos_e > 0)
	{
		if (*(int *)head -> content > *(int *)(*stack) -> content)
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
    while (stack)
    {
        if (*(int *)head -> content < *(int *)stack -> content)
            break ;
        stack = stack -> next;
		pos_h++;
    }
	printf("ph = %d\n", pos_h);
	pos_e = ft_find_pos_e(&head);
	printf("pe = %d\n", pos_e);
	if (pos_e < pos_h)
		return (1);
	return (0);
}

void    ft_sort_stack(t_list **stack)
{
    t_list  *head;
    t_list  *second;
    t_list  *end;
	int	pos;

    if (!stack || !*stack)
        return ;
    head = *stack;
    second = (*stack) -> next;
	pos = 0;
    while (*stack)
    {
        if (*(int *)head -> content > *(int *)(*stack) -> content)
            break ;
        *stack = (*stack) -> next;
		pos++;
    }
}