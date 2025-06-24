#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int main(void)
{
    char *a = (char *)ft_calloc(13, sizeof(char));
    char *b = "hola que tal";
    int i = 0;
    while (b[i])
    {
        a[i] = b[i];
        i++;
    }
    printf("%s\n", a);
    // *(int *)a = 1234151;
    printf("%d\n", *(int *)a);
    printf("%d\n", strcmp(a, "hola que tal"));
}