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
    new->R_width = WIN_W;
    new->R_height = WIN_H;
}

//не поместилось по норме
int	print_background(t_info *o)
{
	int	i;
	int	j;

	j = -1;
	while (++j < (o->R_width / 2))
	{
		i = -1;
		while (++i < o->R_height)
			mlx_pixel_put(o->mlx, o->wind, i, j, o->F);
	}
	j--;
	while (++j < o->R_width)
	{
		i = -1;
		while (++i < o->R_height)
			mlx_pixel_put(o->mlx, o->wind, i, j, o->C);
	}
	return (0);
}
