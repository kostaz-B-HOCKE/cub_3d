#include "libft.h"

void    ft_print_darr(char **argv, int fd)
{
    int i;

    i = 0;
    if (argv)
    {
        while (argv[i]) {
            ft_putstr_fd(argv[i++], fd);
        }
    }
}