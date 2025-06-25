#include "push_swap.h"

void	ft_swap_a(t_list **stack)
{
	t_list	*node;

	if (!*stack || !(*stack) -> next)
		return ;
	node = (*stack) -> next;
	(*stack) -> next = node -> next;
	node -> next = *stack;
	*stack = node;
	write(1, "sa\n", 3);
	return ;
}

void	ft_swap_b(t_list **stack)
{
	t_list	*node;

	if (!*stack || !(*stack) -> next)
		return ;
	node = (*stack) -> next;
	(*stack) -> next = node -> next;
	node -> next = *stack;
	*stack = node;
	write(1, "sb\n", 3);
	return ;
}

void	ft_swap_s(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	if (!*stack_a || !(*stack_a) -> next || !*stack_b || !(*stack_b) -> next)
		return ;
	node = (*stack_a) -> next;
	(*stack_a) -> next = node -> next;
	node -> next = *stack_a;
	*stack_a = node;
	node = (*stack_b) -> next;
	(*stack_b) -> next = node -> next;
	node -> next = *stack_b;
	*stack_b = node;
	write(1, "ss\n", 3);
	return ;
}

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*t;

	if (!*stack_b)
		return ;
	t = *stack_b;
	*stack_b = t -> next;
	t -> next = *stack_a;
	*stack_a = t;
	write(1, "pa\n", 3);
	return ; 
}

void	ft_push_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*t;

	if (!*stack_a)
		return ;
	t = *stack_a;
	*stack_a = t -> next;
	t -> next = *stack_b;
	*stack_b = t;
	write(1, "pb\n", 3);
	return ; 
}

void	ft_rev_rot_a(t_list **stack)
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
	write(1, "rra\n", 4);
	return ;
}

void	ft_rev_rot_b(t_list **stack)
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
	write(1, "rrb\n", 4);
	return ;
}

void	ft_rev_rot_r(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*node;

	if (!*stack_a || !(*stack_a) -> next || !*stack_b || !(*stack_b) -> next)
		return ;
	node = *stack_a;
	while (node && node -> next && (node -> next) -> next)
		node = node -> next;
	last = node -> next;
	node -> next = NULL;
	last -> next = *stack_a;
	*stack_a = last;
	node = *stack_b;
	while (node && node -> next && (node -> next) -> next)
		node = node -> next;
	last = node -> next;
	node -> next = NULL;
	last -> next = *stack_b;
	*stack_b = last;
	write(1, "rrr\n", 4);
	return ;
}

void	ft_rotate_a(t_list **stack)
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
	write(1, "ra\n", 4);
	return ;
}

void	ft_rotate_b(t_list **stack)
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
	write(1, "rb\n", 4);
	return ;
}

void	ft_rotate_r(t_list **stack_a, t_list **stack_b)
{
	t_list	*t;
	t_list	*start;

	if (!*stack_a || !(*stack_a) -> next || !*stack_b || !(*stack_b) -> next)
		return ;
	start = *stack_a;
	*stack_a = start -> next; 
	t = ft_lstlast(*stack_a);
	t -> next = start;
	start -> next = NULL;
	start = *stack_b;
	*stack_b = start -> next; 
	t = ft_lstlast(*stack_b);
	t -> next = start;
	start -> next = NULL;
	write(1, "rr\n", 4);
	return ;
}