#include "../include/cubd.h"

void    init_info(t_info *new)
{
    new->argv = NULL;
    // new->check = NULL;
    new->C = 0;
    new->F = 0;
    new->mlx = NULL;
    new->s_str = NULL;
    new->NO = NULL;
    new->SO = NULL;
    new->WE = NULL;
    new->EA = NULL;
    new->x = 0;
    new->y = 0;
    new->fd = 0;
    new->R_width = 480;
    new->R_height = 840;
}
