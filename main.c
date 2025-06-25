
#include "push_swap.h"


int main(int argc, char **argv)
{
	t_list	*stack = ft_stack_a(argc, argv);

	// ft_lstiter(stack, ft_print_content);
    ft_sort_stack_a(&stack);
    // ft_lstiter(stack, ft_print_content);
	ft_lstclear(&stack, free);
}

    // char *a = (char *)ft_calloc(13, sizeof(char));
    // char *b = "hola que tal";
    // int i = 0;
    // while (b[i])
    // {
    //     a[i] = b[i];
    //     i++;
    // }
    // printf("%s\n", a);
    // // *(int *)a = 1234151;
    // printf("%d\n", *(int *)a);
    // printf("%d\n", strcmp(a, "hola que tal"));