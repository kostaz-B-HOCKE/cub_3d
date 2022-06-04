#include "../include/cubd.h"

void    free_info(t_info **info)
{
    ft_free_darr((*info)->argv);
    if (*info)
        free(*info);
}

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
