#include "push_swap.h"

int ft_find_pivot(t_list *stack_a)
{
    t_list  *ordered_list;
    t_list  *start;
    int i;
    int pivot;
    
    i = 0;
    ordered_list = ft_quickshort(stack_a);
    start = ordered_list;
    while (i < ft_lstsize(stack_a) / 2)
    {
        ordered_list = ordered_list -> next;
        i++;
    }
    pivot = *(int *)ordered_list -> content;
    ft_lstclear(&start, free);
    return (pivot);
}

int	ft_push_swap(t_list **stack_a, t_list **stack_b)
{   
    int pivot;
    int i;
    int size;

    pivot = ft_find_pivot(*stack_a);
    i = 0;
    size = ft_lstsize(*stack_a);
    while (i < size)
    {
        if (*(int *)(*stack_a) -> content > pivot)
        {
            ft_push(stack_b, stack_a);
            write (1, "pb\n", 3);
            ft_rev_rot(stack_b);
            write (1, "rrb\n", 4);
        }
        else
        {
            ft_rotate(stack_a);
            write(1, "ra\n", 3);
        }
        i++;
    }
    printf("stack_b = ");
    ft_lstiter(*stack_b, ft_print_content);
    printf("\n");
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
    if (argc <= 5)
        return (ft_few_args(&stack_a), ft_lstclear(&stack_a, free), 0);
    content = ft_strdup("Eliminar este nodo");
    if (!content)
        return (1);
    stack_b = ft_lstnew(content);
    ft_push_swap(&stack_a, &stack_b);
    printf("stack_a = ");
    ft_lstiter(stack_a, ft_print_content);
    ft_lstclear(&stack_a, free);
    ft_lstclear(&stack_b, free);
    return (0);
}