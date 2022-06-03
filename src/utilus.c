#include "../include/cubd.h"


int   ft_error(char *str)
{
    ft_putstr_fd("Error: ", 2);
    ft_putstr_fd(str, 2);
    return (1);
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

void    ft_print_darr(char **argv, int fd)
{
    int i;

    i = 0;
    if (argv)
    {
        while (argv[i]) {
            ft_putstr_fd(argv[i++], fd);
            ft_putstr_fd("\n", fd);
        }
    }
}