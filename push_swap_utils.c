#include "push_swap.h"

t_list	*ft_load_stackn(int size)
{
	t_list	*t;
	t_list	*stack_b;
	int	content;
	int	i;

	i = 0;
	content = '0';
	stack_b = ft_lstnew(ft_copy_content(&content));
	if (!stack_b)
		return (NULL);
	while (i < size)
	{
		t = ft_lstnew(ft_copy_content(&content));
		if (!t)
			return (NULL);
		ft_lstadd_back(&stack_b, t);
		i++;
	}
	return (stack_b);
}

void	ft_swap_s(t_list **stack)
{
	t_list	*node;

	if (!*stack || !(*stack) -> next)
		return ;
	node = (*stack) -> next;
	(*stack) -> next = node -> next;
	node -> next = *stack;
	*stack = node;
	return ;
}

void	ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*t;

	if (!*stack_b)
		return ;
	t = *stack_b;
	*stack_b = t -> next;
	t -> next = *stack_a;
	*stack_a = t;
	return ; 
}

void	ft_rev_rot(t_list **stack)
{
	t_list	*last;
	t_list	*node;

	if (!*stack || !(*stack) -> next)
		return ;
	node = *stack;
	while (node && node -> next && (node -> next) -> next)
		node = node -> next;
	last = node -> next;
	node -> next = NULL;
	last -> next = *stack;
	*stack = last;
	return ;
}

void	ft_rotate(t_list **stack)
{
	t_list	*t;
	t_list	*start;

	if (!*stack || !(*stack) -> next)
		return ;
	start = *stack;
	*stack = start -> next; 
	t = ft_lstlast(*stack);
	t -> next = start;
	start -> next = NULL;
	return ;
}