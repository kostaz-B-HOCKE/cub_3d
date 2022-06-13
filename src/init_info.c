#include "../include/cubd.h"

void    init_info(t_info *new)
{
//    *new = (t_info*)malloc(sizeof(t_info*));
//    if (!new)
//        return ;
//    (*new)->F = malloc(sizeof(int) * 3);
//    if (!(*new)->F)
//        exit(1);
//    (*new)->F[3] = 0;
//    (*new)->S = malloc(sizeof(int) * 3);
//    if (!(*new)->S)
//        exit(1);
    (new)->argv = NULL;
    new->check = NULL;
    (new)->height = 720;
    (new)->width = 480;
    new->x = -1;
    new->y = -1;
}
