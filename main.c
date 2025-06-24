#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int main(void)
{
    int *a = (int *)ft_calloc(sizeof(int) + 1, sizeof(char));
    *a = 2;
    printf("%d\n", *a);
    printf("%d\n", strcmp(a, "hola que tal"));
}