
#include "push_swap.h"
#include "libft/libft.h"


int main(int argc, char **argv)
{
	t_list	*stack = ft_stack_a(argc, argv);
    printf("s = %p\n", stack);
    ft_lstiter(stack, ft_print_content);
    t_list *min = ft_find_min(stack);
    printf("\n s = %p = p\n", stack);
    ft_lstiter(stack, ft_print_content);
    // ft_print_content(stack ->content);
    printf("\n min = %p\n", min);
    printf("%d\n", *(int *)min->content);
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