#include "../include/cubd.h"

void    init_info(t_info **new)
{
    *new = (t_info*)malloc(sizeof(t_info*));
    if (!*new)
        return ;
    (*new)->F = malloc(sizeof(int) * 3);
    (*new)->S = malloc(sizeof(int) * 3);// набросок
    (*new)->argv = NULL;
    (*new)->height = 0;
    (*new)->width = 0;
}
