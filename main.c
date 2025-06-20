#include "libft/libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 0;
    if (argc)
    {
        while (argv[i])
        {
            printf("%s\n", argv[i]);
            i++;
        }
        printf("%p\n", argv[i]);
    }
}