#include "push_swap.h"

t_list  *ft_find_a_target(t_list *head, t_list *stack)
{
	t_list	*r;
	int	closest;
	int	content;
	int	content_b;

	if (!head || !stack)
		return (NULL);
	closest = INT_MIN;
	content = *(int *)head -> content;
	r = NULL;
	while (stack)
	{
		content_b = *(int *)stack -> content;
		if (content_b < content && content_b >= closest)
		{
			r = stack;
			closest = content_b;
		}
		stack = stack -> next;
	}
	return (r);
}

t_list  *ft_find_b_target(t_list *head, t_list *stack)
{
	t_list	*r;
	int	closest;
	int	content;
	int	content_a;

	if (!head || !stack)
		return (NULL);
	closest = INT_MAX;
	content = *(int *)head -> content;
	r = NULL;
	while (stack)
	{
		content_a = *(int *)stack -> content;
		if (content_a < content && content_a <= closest)
		{
			r = stack;
			closest = content_a;
		}
		stack = stack -> next;
	}
	return (r);
}

int	ft_choose_operation(t_list *stack, t_list *node)
{
	int	size;
	int	pos;

    if (!stack)
        return (INT_MIN);
	size = ft_lstsize(stack);
	pos = 0;
	while (stack)
	{
		if (*(int *)stack -> content == *(int *)node -> content)
			break;
		pos++;
		stack = stack -> next;
	}
	if (pos <= (size / 2))
		return (pos);
	pos = size - pos;
	return (-pos);
}
