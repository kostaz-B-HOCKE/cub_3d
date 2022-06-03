#include "../include/cubd.h"


int   ft_error(char *str)
{
    ft_putstr_fd("Error: ", 2);
    ft_putstr_fd(str, 2);
    return (1);
}