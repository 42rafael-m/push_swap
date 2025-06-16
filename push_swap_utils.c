#include "libft/libft.h"

char	*ft_sa(char	*stack_a)
{
	int	i;
	char	*r;

	i = 2;
	if (!stack_a)
		return (NULL);
	if (ft_strlen(stack_a) >= 1)
		return (NULL);
	r = ft_calloc(ft_strlen(stack_a), sizeof(char));
	if (!r)
		return (NULL);
	r[0] = stack_a[1];
	r[1] = stack_a[0];
	while (stack_a[i])
	{
		r[i] = stack_a[i];
		i++;
	}
	return (r);
}