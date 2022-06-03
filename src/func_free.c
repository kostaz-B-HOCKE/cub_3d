#include "../include/cubd.h"

void    free_info(t_info **info)
{
    ft_free_darr((*info)->argv);
    if (*info)
        free(*info);
}