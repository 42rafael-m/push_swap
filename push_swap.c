#include "libft/libft.h"
#include "push_swap.h"

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
        if (!len)
            return (1);
        while (i < ft_strlen(argv[argc]))
        {
            if (ft_strchr(INV_CHARS, argv[argc][i]))
                return (1);
            i++;
        }
        if (argv[argc][0] != 0 && ft_atoi(argv[argc] == 0))
            return (1);
        argc--;
    }
    return (0);
}

char    **ft_stack(int argc, char **argv)
{
    char    **stack;
    int i;

    i = 0;
    if (!argv)
        return (NULL);
    stack = (char **)ft_calloc(argc, sizeof(char *));
    if (!stack)
        return (NULL);
    argc--;
    while (argv[argc] > 0)
    {
        stack[argc] = ft_strdup(argv[argc]);
        if (!stack[argc])
            return (NULL);
        argc--;
    }
}

int main(int argc, char **argv)
{
    char    **stack_a;
    char    **stack_b;

    if (argc <= 1)
        return (write(2, "Error\n", 6), 1);
    if (ft_valid_args == 1)
        return (write(2, "Error\n", 6), 1);
    stack_a = ft_stack(argc, argv);
    if (!stack_a)
        return (1);
    stack_b = (char *)ft_calloc(argc, sizeof(char));
    if (!stack_b)
        return (1);
    return (0);
}