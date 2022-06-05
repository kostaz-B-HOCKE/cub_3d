#include "../include/cubd.h"

int check_digit_str(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (!ft_isdigit(str[i]))
            return (ft_error("bad argument.\n"));
    }
    return (0);
}

int   ft_error(char *str)
{
    ft_putstr_fd("Error: ", 2);
    ft_putstr_fd(str, 2);
    exit(1);
    return (1);
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
    else
        ft_putstr_fd("no ARGV\n", fd);
}
