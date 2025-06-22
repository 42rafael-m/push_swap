#include "push_swap.h"

void	*ft_copy_content(void *content)
{
	int	*copy;

	copy = malloc(sizeof(int));
	if (!copy)
		return (NULL);
	*copy = *(int *)content;
	return ((void *)copy);
}

int	ft_choose_pivot(t_list *list)
{
	int	pivot;
	int	a;
	int	b;
	int	c;

	a = *(int *)list -> content;
	list = list -> next;
	b = *(int *)list -> content;
	list = list -> next;
	c = *(int *)list -> content;
	if ((a > b && a < c) || (a > c && a < b))
		return (a);
	if ((b > a && b < c) || (b > c && b < a))
		return (b);
	return (c);
}

int	ft_quickshort(t_list *list)
{
	int pivot;

	pivot = ft_choose_pivot(list);
	
}