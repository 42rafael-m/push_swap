#include "push_swap.h"

int ft_find_pivot(t_list *stack_a)
{
    t_list  *ordered_list;
    int i;
    int size;
    
    i = 0;
    size = ft_lstsize(stack_a);
    ordered_list = ft_quickshort(stack_a);
    while (i < (size / 2))
    {
        ordered_list = ordered_list -> next;
        i++;
    }
    return (*(int *)ordered_list -> content);
}

int	ft_push_swap(t_list **stack_a, t_list **stack_b)
{   
    int pivot;
    t_list  *sa;
    t_list  *sb;
    int i;

    sa = *stack_a;
    sb = *stack_b;
    pivot = ft_find_pivot(sa);
    i = 0;
    while (i < ft_lstsize(sa))
    {
        if (*(int *)sa -> content > pivot)
        {
            ft_push(&sa, &sb);
            write (1, "pb\n", 3);
            ft_rev_rot(&sb);
            write (1, "rrb\n", 4);
            // printf("sa = %d\n", *(int *)sa -> content);
            // printf("sb = %d\n", *(int *)sb -> content);
        }
        else
        {
            ft_rotate(&sa);
            write(1, "ra\n", 3);
            // printf("sa = %d\n", *(int *)sa -> content);
        }
        i++;
    }
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

int main(int argc, char **argv)
{
    t_list    *stack_a;
    t_list    *stack_b;
 
    if (argc <= 1)
        return (write(2, "Error\n", 6), 1);
    if (ft_valid_args(argc, argv) == 1)
        return (write(2, "Error\n", 6), 1);
    stack_a = ft_stack_a(argc, argv);
    if (!stack_a)
        return (write(2, "Error\n", 6), 3);
    stack_b = ft_load_stackn(argc / 2);
    if (!stack_b)
        return (write(2, "Error\n", 6), 1);
    ft_push_swap(&stack_a, &stack_b);
    return (0);
}