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

char	**ft_sa(char	**stack_a)
{
	int	i;
	char	**r;

	i = 2;
	if (!stack_a)
		return (NULL);
	if (ft_dptr_len(stack_a) <= 1)
		return (NULL);
	r = (char **)ft_calloc(ft_dptr_len(stack_a) + 1, sizeof(char *));
	if (!r)
		return (NULL);
	r[0] = ft_strdup(stack_a[1]);
	r[1] = ft_strdup(stack_a[0]);
	while (stack_a[i])
	{
		r[i] = ft_strdup(stack_a[i]);
		i++;
	}
	r[i] = NULL;
	return (r);
}

// int	main()
// {
// 	char *s[4] = {"123", "-44", "0", NULL};
// 	char **r = ft_sa(s);
// 	int i = 0;
// 	while (i < 4)
// 	{
// 		if (r[i])
// 		{
// 			printf("%s\n", r[i]);
// 			free (r[i]);
// 		}
// 		i++;
// 	}
// 	free (r);
// }