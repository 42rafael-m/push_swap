#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

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

char    **ft_stack(int argc, char **argv)
{
    char    **stack;
	int	i;

	i = 0;
    if (!argv)
        return (NULL);
    stack = (char **)ft_calloc(argc, sizeof(char *));
    if (!stack)
        return (NULL);
    while (i < (argc - 1))
    {
        stack[i] = ft_strdup(argv[i + 1]);
        if (!stack[i])
            return (NULL);
        i++;
    }
	stack[i] = NULL;
	return (stack);
}

int main(int argc, char **argv)
{
    char    **stack_a;
    char    **stack_b;

    if (argc <= 1)
        return (write(2, "Error\n", 6), 1);
    if (ft_valid_args(argc, argv) == 1)
        return (write(2, "Error\n", 6), 1);
    stack_a = ft_stack(argc, argv);
    if (!stack_a)
        return (write(2, "Error\n", 6), 3);
    stack_b = (char **)ft_calloc(argc, sizeof(char *));
    if (!stack_b)
        return (write(2, "Error\n", 6), 1);
		int i = 0;
    while (stack_a[i])
	{
		write(1, stack_a[i], ft_strlen(stack_a[i]));
		write(1, "\n", 1);
		i++;
	}
    return (0);
}