#include "libft.h"

void    ft_free_darr(char **argv)
{
    int i;

    i = 0;
    if (argv)
    {
        while (argv[i])
        {
            if (argv[i])
                free(argv[i]);
            i++;
        }
        free(argv);
    }
}