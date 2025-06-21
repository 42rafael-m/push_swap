#include "libft/libft.h"
#include "push_swap.h"

size_t	ft_dptr_len(char **dptr)
{
	int	i;

	i = 0;
	if (!dptr)
		return (0);
	while (dptr[i])
		i++;
	return (i);
}

void	ft_swap_s(t_list **stack)
{
	t_list	*node;

	if (!*stack || !(*stack) -> next)
		return ;
	node = (*stack) -> next;
	(*stack) -> next = node -> next;
	node -> next = *stack;
	*stack = node;
	return ;
}

void	ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*t;

	if (!*stack_b)
		return ;
	t = *stack_b;
	*stack_b = t -> next;
	t -> next = *stack_a;
	*stack_a = t;
	return ; 
}

void	ft_rev_rot(t_list *stack)
{
	
	return ;
}

char	**ft_rotate(char **stack)
{
	char	*first;
	size_t	len;
	size_t	i;

	i = 0;
	if (!stack)
		return (NULL);
	first = stack[0];
	len = ft_dptr_len(stack);
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = first;
	return (stack);
}

/* #include <stdio.h>
int	main()
{
	char **s = (char **)calloc(4, sizeof(char *));
	s[0] = ft_strdup("123");
	s[1] = ft_strdup("-44");
	s[2] = ft_strdup("0");
	s[3] = NULL;
	char **s2 = (char **)calloc(4, sizeof(char *));
	s2[0] = ft_strdup("1");
	s2[1] = ft_strdup("-44");
	s2[2] = ft_strdup("0");
	s2[3] = NULL;
	s = ft_rev_rot(s);
	int i = 0;
	while (i < 4)
	{
		if (s[i])
		{
			printf("%s\n", s[i]);
			free (s[i]);
		}
		i++;
	}
	free (s);
	ft_free_d(s2);
} */