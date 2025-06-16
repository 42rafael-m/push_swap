#include "libft/libft.h"

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

char	**ft_swap_(char	**stack)
{
	int	i;
	char	**r;

	i = 2;
	if (!stack)
		return (NULL);
	if (ft_dptr_len(stack) <= 1)
		return (NULL);
	r = (char **)ft_calloc(ft_dptr_len(stack) + 1, sizeof(char *));
	if (!r)
		return (NULL);
	r[0] = ft_strdup(stack[1]);
	r[1] = ft_strdup(stack[0]);
	while (stack[i])
	{
		r[i] = ft_strdup(stack[i]);
		i++;
	}
	r[i] = NULL;
	free (stack);
	stack = NULL;
	return (r);
}

char	**ft_push(char **stack_a, char **stack_b)
{
	char	*t;
	size_t	len;

	if (!stack_b)
		return (stack_a);
	t = stack_a[0];
	stack_a[0] = ft_strdup(stack_b[0]);
	free(t);
	t = NULL;
	return (stack_a); 
}

// int	main()
// {
// 	char **s = (char **)calloc(4, sizeof(char *));
// 	s[0] = ft_strdup("123");
// 	s[1] = ft_strdup("-44");
// 	s[2] = ft_strdup("0");
// 	s[3] = NULL;
// 	char **s2 = (char **)calloc(4, sizeof(char *));
// 	s2[0] = ft_strdup("1");
// 	s2[1] = ft_strdup("-44");
// 	s2[2] = ft_strdup("0");
// 	s2[3] = NULL;
// 	s = ft_push(s, s2);
// 	int i = 0;
// 	while (i < 4)
// 	{
// 		if (s[i])
// 		{
// 			printf("%s\n", s[i]);
// 			free (s[i]);
// 		}
// 		i++;
// 	}
// 	free (s);
// 	ft_free_d(s2);
// }