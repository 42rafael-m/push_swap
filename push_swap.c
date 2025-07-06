#include "push_swap.h"

t_list	*ft_find_max(t_list *list)
{
    t_list  *r;
    int max;

    max = INT_MIN;
	if (!list)
		return (NULL);
	r = list;
    while (list)
    {
        if (*(int *)list -> content > max)
        {
            r = list;
            max = *(int *)list -> content;
        }
        list = list -> next;
    }
    return (r);
}

t_list	*ft_find_min(t_list *list)
{
    t_list  *r;
    int min;

	if (!list)
		return (NULL);
	r = list;
    min = INT_MAX;
    while (list)
    {
        if (*(int *)list -> content < min)
        {
            r = list;
            min = *(int *)list -> content;
        }
        list = list -> next;
    }
    return (r);
}

t_list	*ft_choose_target_b(t_list **stack_b, t_list **stack_a)
{
	unsigned int	total;
	int cost_a;
	int	cost_b;
	t_list *target;
	t_list *node;

	total = INT_MAX;
	target = NULL;
	node = *stack_b;
	while (node)
	{
		if (total <= (ft_abs(ft_choose_op(*stack_a, ft_find_node_target_b(node, *stack_a))) + ft_abs(ft_choose_op(*stack_b, node))))
		{
			node = node -> next;
			continue ;
		}
		target = ft_find_node_target_b(node, *stack_a);
		if (!target)
			return (NULL);
		// printf("target_b = %d\n", *(int *)target -> content);
		cost_a = ft_choose_op(*stack_a, target);
		cost_b = ft_choose_op(*stack_b, node);
		// printf("ca = %d, cb = %d\n", cost_a, cost_b);
		total = ft_abs(cost_a) + ft_abs(cost_b);

		if (cost_a == INT_MIN || cost_b == INT_MIN)
			return (NULL);
		node = node -> next;
	}
	ft_rotate_cost(cost_a, cost_b, stack_a, stack_b);
	// ft_lstiter((*stack_a), ft_print_content);
	// printf("\n");
	// ft_lstiter((*stack_b), ft_print_content);
	// printf("\n");
	return (target);
}

t_list	*ft_choose_target_a(t_list **stack_a, t_list **stack_b)
{
	unsigned int	total;
	int	cost_a;
	int	cost_b;
	t_list *target;
	t_list *node;

	total = INT_MAX;
	target = NULL;
	node = *stack_a;
	while (node)
	{
		if (total <= (ft_abs(ft_choose_op(*stack_b, ft_find_node_target_a(node, *stack_a))) + ft_abs(ft_choose_op(*stack_a, node))))
		{
			node = node -> next;
			continue ;
		}
		total = ft_abs(cost_a) + ft_abs(cost_b);
		target = ft_find_node_target_a(*stack_a, node);
		if (!target)
			return (NULL);
		cost_a = ft_choose_op(*stack_b, ft_find_node_target_a(node, *stack_a));
		cost_b = ft_choose_op(*stack_a, node);
		if (cost_a == INT_MIN || cost_b == INT_MIN)
			return (NULL);
		node = node -> next;
	}
	ft_rotate_cost(cost_a, cost_b, stack_a, stack_b);
	return (target);
}

int	ft_rotate_cost(int cost_a, int cost_b, t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || ! stack_b || !*stack_a || !*stack_b)
		return (1);
	if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			ft_rotate_r(stack_a, stack_b);
			cost_a--;
			cost_b--;
		}
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			ft_rev_rot_r(stack_a, stack_b);
			cost_a++;
			cost_b++;
		}
	}
	if (cost_b > 0)
		while (cost_b-- > 0)
			ft_rotate_b(stack_b);
	else if (cost_b < 0)
		while (cost_b++ < 0)
			ft_rev_rot_b(stack_b);
	if (cost_a < 0)
		while (cost_a++ < 0)
			ft_rev_rot_a(stack_a);
	else if (cost_a > 0)
		while (cost_a-- > 0)
			ft_rotate_a(stack_a);
	return (0);
}
int	ft_push_swap_a(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return (1);
	while (ft_lstsize(*stack_a) > 4)
	{
		if (!ft_strncmp((char *)(*stack_b) -> content, "Eliminar este nodo", 19))
		{
			ft_push_a(stack_a, stack_b);
			ft_lstdelone(ft_lstlast(*stack_b), free);
			(*stack_b) -> next = NULL;
			continue ;
		}
		ft_choose_target_a(stack_a, stack_b);
		ft_push_a(stack_a, stack_b);
	}
	ft_sort_four(stack_a);
	// ft_lstiter((*stack_a), ft_print_content);
	// printf("\n");
	// ft_lstiter((*stack_b), ft_print_content);
	// printf("\n");
	return (0);
}

int	ft_push_swap_b(t_list **stack_a, t_list **stack_b)
{
	int	op;

	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return (1);
	op = 0;
	while (ft_lstsize(*stack_b) > 0)
	{
		ft_choose_target_b(stack_b, stack_a);
		ft_push_b(stack_b, stack_a);
	}
	// ft_lstiter(*stack_a, ft_print_content);
	// printf("\n");
	op = ft_choose_op(*stack_a, ft_find_min(*stack_a));
	// printf("op = %d\n", op);
	ft_rotate_cost(op, 0, stack_a, stack_a);
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
		return (ft_few_args(&stack_a), ft_lstiter(stack_a, ft_print_content), 0);
    content = ft_strdup("Eliminar este nodo");
    if (!content)
        return (1);
    stack_b = ft_lstnew(content);
	if (!stack_b)
		return (1);
    ft_push_swap_a(&stack_a, &stack_b);
	ft_push_swap_b(&stack_a, &stack_b);
	ft_lstiter(stack_a, ft_print_content);
    return (0);
}