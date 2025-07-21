/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael-m <rafael-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:39:27 by rafael-m          #+#    #+#             */
/*   Updated: 2025/07/21 12:34:24 by rafael-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_valid_args(int argc, char **argv)
{
	size_t	len;
	size_t	i;

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

t_list	*ft_stack_a(int argc, char **argv)
{
	t_list	*stack;
	t_list	*node;
	int		*content;
	int		i;

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

// void	ft_print_content(void *s)
// {
// 	printf("%d ", *(int *)s);
// 	return ;
// }

t_list	*ft_load_stck_a(int *argc, char **argv)
{
	t_list	*stack_a;
	char	*t;

	if (*argc == 2 && ft_strchr(argv[1], ' '))
	{
		t = ft_strjoin("1 ", argv[1]);
		argv = ft_split(t, ' ');
		free(t);
		if (!argv)
			return (write(2, "Error\n", 6), NULL);
		*argc = ft_doubleptr_len(argv);
		if (ft_valid_args(*argc, argv) == 1)
			return (ft_free_d(argv), write(2, "Error\n", 6), NULL);
		stack_a = ft_stack_a(*argc, argv);
		ft_free_d(argv);
	}
	else
	{
		if (ft_valid_args(*argc, argv) == 1)
			return (write(2, "Error\n", 6), NULL);
		stack_a = ft_stack_a(*argc, argv);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*content;

	if (argc <= 1)
		return (0);
	stack_a = ft_load_stck_a(&argc, argv);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	if (argc <= 4)
	{
		ft_sort_three(&stack_a);
		while (stack_a != ft_find_min(stack_a))
			ft_rev_rot_a(&stack_a);
		return (ft_lstclear(&stack_a, free), 0);
	}
	content = ft_strdup("Eliminar este nodo");
	stack_b = ft_lstnew(content);
	if (!stack_b)
		return (write(2, "Error\n", 6), free(content), 1);
	ft_push_swap_a(&stack_a, &stack_b);
	ft_push_swap_b(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
