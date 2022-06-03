#include "../include/cubd.h"

void    init_info(t_info **new)
{
    *new = (t_info*)malloc(sizeof(t_info*));
    if (!*new)
        return ;
    (*new)->argv = NULL;
    (*new)->height = 0;
    (*new)->width = 0;
}