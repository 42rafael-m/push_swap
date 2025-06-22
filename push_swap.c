#include "push_swap.h"
#include <stdio.h>

int	ft_push_swap(t_list *stack_a, t_list *stack_b)
{
    t_list  *ordered_list;
    t_list  *t;
    int i;
    int size;
    int pivot;

    i = 0;
    size = ft_lstsize(stack_a);
    ordered_list = ft_quickshort(stack_a);
    while (ordered_list)
    {
        printf("%d\n", *(int *)ordered_list -> content);
        ordered_list = ordered_list -> next;
    }
    t = stack_a;
    while (i < size && stack_a -> next)
    {
        t = stack_a -> next;
        i++;
    }
    pivot = *(int *)t -> content;
    ft_lstsize(stack_b);
    printf("%d\n", pivot);
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

t_list    *ft_stack(int argc, char **argv)
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
    while (i < (argc - 1))
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

int main(int argc, char **argv)
{
    t_list    *stack_a;
    t_list    *stack_b;
    int content;

    if (argc <= 1)
        return (write(2, "Error\n", 6), 1);
    if (ft_valid_args(argc, argv) == 1)
        return (write(2, "Error\n", 6), 1);
    stack_a = ft_stack(argc, argv);
    if (!stack_a)
        return (write(2, "Error\n", 6), 3);
    content = 0;
    stack_b = ft_lstnew(&content);
    if (!stack_b)
        return (write(2, "Error\n", 6), 1);
    ft_push_swap(stack_a, stack_b);
	// int i = 0;
    // while (stack_a[i])
	// {
	// 	write(1, stack_a[i], ft_strlen(stack_a[i]));
	// 	write(1, "\n", 1);
	// 	i++;
	// }

    return (0);
}