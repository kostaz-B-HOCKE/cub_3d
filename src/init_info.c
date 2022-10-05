#include "../include/cubd.h"

void    init_info(t_info *new)
{
    new->argv = NULL;
    // new->check = NULL;
    // new->height = 720;
    // new->width = 480;
    // new->R = 840,480
    // new->C = 51,198,227;
    // new->F = 184,113,39;
    new->s_str = NULL;
    new->NO = NULL;
    new->SO = NULL;
    new->WE = NULL;
    // new->EA = NULL;
    new->x = 0;
    new->y = 0;
    new->fd = 0;
    new->R_width = 840;
    new->R_height = 480;
}
