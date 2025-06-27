#include "push_swap.h"

t_list	*ft_find_max(t_list **list)
{
    t_list  *r;
    int max;

    max = INT_MAX;
    while (list)
    {
        if (*(int *)(*list) -> content > max)
        {
            r = *list;
            max = (*list) -> content;
        }
        list = (*list) -> next;
    }
    return (*list);
}

t_list	*ft_find_min(t_list **list)
{
    t_list  *r;
    int min;

    min = INT_MIN;
    while (list)
    {
        if (*(int *)(*list) -> content < min)
        {
            r = *list;
            min = (*list) -> content;
        }
        list = (*list) -> next;
    }
    return (*list);
}

int	ft_push_swap(t_list **stack_a, t_list **stack_b)
{   
    int  head_a;
    int  head_b;
	t_list	*t;
    int  end_b;
	int	max;
	int	min;
	int	i;

	t = *stack_b;
	i = 0;
	max = ft_find_max(*stack_a);
	min = ft_find_min(*stack_a);
    while (*stack_a)
    {
        head_a = *(int *)(*stack_a) -> content;
        head_b = *(int *)(*stack_b) -> content;
        end_b = *(int *)(ft_lstlast(*stack_b)) -> content;
		printf("ha = %d\n", head_a);
		printf("hb = %d\n", head_b);
		printf("eb = %d\n", end_b);
		if (*stack_b == t)
		{
			ft_push_a(stack_a, stack_b);
			ft_lstdelone(t, free);
			(*stack_b) -> next = NULL;
			t = NULL;
		}
		else if (head_a == min || (head_a < head_b && head_a > end_b))
            ft_push_a(stack_a, stack_b);
        else if (head_a == max || head_a > ft_find_max(*stack_b))
		{
			printf("Hola\n");
			while (*(int *)(*stack_b) -> content < ft_find_max(*stack_b))
				ft_rotate_b(stack_b);
			ft_push_a(stack_a, stack_b);
			ft_swap_b(stack_b);
		}
        else 
			ft_rotate_b(stack_b);
        i++;
    }
	ft_lstiter(*stack_b, ft_print_content);
	printf("\n");
	while (!ft_is_sorted(*stack_b))
		ft_rev_rot_b(stack_b);
	while (*stack_b)
		ft_push_b(stack_b, stack_a);
	return (0);
}

int ft_valid_args(int argc, char **argv)
{
    size_t  len;
    size_t  i;

    i = 0;
    if (!argv || argc <= 0)
        return (1);
    argc--;
    while (argc > 0)
    {
        len = ft_strlen(argv[argc]);
        if (!len && argv[argc][0] != 0)
            return (1);
        while (i < ft_strlen(argv[argc]))
        {
			if (ft_atol(argv[argc]) > INT_MAX || ft_atol(argv[argc]) < INT_MIN)
				return (1);
            if (ft_strchr(INV_CHARS, argv[argc][i]))
                return (1);
            i++;
        }
        if ((argv[argc][0] != 48) && (ft_atoi(argv[argc]) == 0))
            return (1);
        argc--;
    }
    return (0);
}

t_list    *ft_stack_a(int argc, char **argv)
{
    t_list	*stack;
	t_list	*node;
	int	*content;
	int	i;

	i = 1;
    if (!argv || argc <= 1)
        return (NULL);
	    node = NULL;
	stack = node;
    while (i < (argc))
    {
        content = (int *)ft_calloc(1, sizeof(int)); 
        *content = ft_atoi(argv[i]);
		node = ft_lstnew(content);
		if (!node)
			return (free(content), NULL);
		ft_lstadd_back(&stack, node);
        i++;
    }
	return (stack);
}

int	ft_is_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack && stack -> next)
	{
		if (*(int *)stack -> content > *(int *)stack -> next -> content)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

int	ft_is_rev_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack && stack -> next)
	{
		if (*(int *)stack -> content < *(int *)stack -> next -> content)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void    ft_print_content(void *s)
{
    printf("%d ", *(int *)s);
    return ; 
}

int main(int argc, char **argv)
{
    t_list    *stack_a;
    t_list    *stack_b;
    char *content;
 
    if (argc <= 1)
        return (write(2, "Error\n", 6), 1);
    if (ft_valid_args(argc, argv) == 1)
        return (write(2, "Error\n", 6), 1);
    stack_a = ft_stack_a(argc, argv);
    if (!stack_a)
        return (write(2, "Error\n", 6), 3);
		if (ft_is_sorted(stack_a))
		return (ft_lstiter(stack_a, ft_print_content), 0);
	if (argc <= 5)
		return (ft_few_args(&stack_a), 0);
    content = ft_strdup("Eliminar este nodo");
    if (!content)
        return (1);
    stack_b = ft_lstnew(content);
    ft_push_swap(&stack_a, &stack_b);
    ft_lstiter(stack_a, ft_print_content);
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
    return (0);
}