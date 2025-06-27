#include "push_swap.h"

t_list  *ft_find_b_target(t_list *head, t_list *stack)
{
	t_list	*r;
	int	closest;
	int	content;
	int	content_b;

	if (!head || !stack)
		return (NULL);
	closest = INT_MIN;
	content = *(int *)head -> content;
	printf("c = %d\n", content);
	r = NULL;
	while (stack)
	{
		content_b = *(int *)stack -> content;
		printf("cb = %d\n", content_b);
		if (content_b < content && content_b >= closest)
		{
			r = stack;
			closest = content_b;
			printf("closest = %d\n", closest);
		}
		stack = stack -> next;
	}
	return (r);
}