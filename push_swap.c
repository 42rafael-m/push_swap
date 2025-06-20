#include "libft/libft.h"
#include "push_swap.h"

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

    if (argc <= 1)
        return (write(2, "Error\n", 6), 1);
    
    return (0);
}