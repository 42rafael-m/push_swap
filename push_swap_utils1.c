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
	int	i;
	int	a;
	int	b;
	int	c;

	i = 0;
	a = *(int *)list -> content;
	c = ft_lstsize(list) / 2;
	while (i < c && list -> next)
	{
		list = list -> next;
		i++;
	}
	b = *(int *)list -> content;
	list = ft_lstlast(list);
	c = *(int *)list -> content;
	if ((a > b && a < c) || (a > c && a < b))
		return (a);
	if ((b > a && b < c) || (b > c && b < a))
		return (b);
	return (c);
}

t_list	*ft_quickshort(t_list *list)
{
	int pivot;
	t_list	*low_list;
	t_list	*big_list;
	t_list	*t;
	t_list	*new_list;
	t_list	*pivot_node;
	
	low_list = NULL;
	big_list = NULL;
	pivot_node = NULL;
	if (!list -> next)
		return (list);
	if (!(list -> next) -> next && list -> content < (list -> next) -> content)
		return (list);
	if (!(list -> next) -> next && list -> content > (list -> next) -> content)
	{
		t = list;
		list = list -> next;
		list -> next = t;
		return (list);
	}
	pivot = ft_choose_pivot(list);
	while (list)
	{
		new_list = ft_lstnew(ft_copy_content(list -> content));
		if (*(int *)new_list -> content < pivot)
			ft_lstadd_back(&low_list, new_list);
		else if (*(int *)new_list -> content == pivot)
			ft_lstadd_back(&pivot_node, new_list);
		else
			ft_lstadd_back(&big_list, new_list);
		list = list -> next;
	}
	new_list = ft_quickshort(low_list);
	ft_lstadd_back(&new_list, pivot_node);
	ft_lstadd_back(&new_list, ft_quickshort(big_list));
	return (new_list);
}