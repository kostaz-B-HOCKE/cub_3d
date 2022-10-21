#include "../include/cubd.h"

int	ft_key_press(int key, t_info *o)
{
	if (key == ESC)
		exit(0);
	else if (key == UP)
    {
        printf("UP\n");
        o->k.kup = 1;
    }	
	else if (key == LEFT)
		o->k.kleft = 1;
	else if (key == DOWN)
		o->k.kdown = 1;
	else if (key == RIGHT)
		o->k.kright = 1;
	else if (key ==ARROW_RIGHT)
		o->k.karr_right = 1;
	else if (key == ARROW_LEFT)
		o->k.karr_left = 1;
	return (0);
}

int	ft_key_release(int key, t_info *o)
{
	if (key == ESC)
		exit(0);
	else if (key == UP)
		o->k.kup = 0;
	else if (key == LEFT)
		o->k.kleft = 0;
	else if (key == DOWN)
		o->k.kdown = 0;
	else if (key == RIGHT)
		o->k.kright = 0;
	else if (key ==ARROW_RIGHT)
		o->k.karr_right = 0;
	else if (key == ARROW_LEFT)
		o->k.karr_left = 0;
	return (0);
}

void	ft_player_rotate_r(t_info *o)
{
	double	old_planeX;
	double	old_dirX;

	old_dirX = o->cast.dirX;
	old_planeX = o->cast.planeX;
	o->cast.dirX = o->cast.dirX * cos(-0.04) - \
					o->cast.dirY * sin(-0.04);
	o->cast.dirY = old_dirX * sin(-0.04) + \
					o->cast.dirY * cos(-0.04);
	o->cast.planeX = o->cast.planeX * cos(-0.04) - \
					o->cast.planeY * sin(-0.04);
	o->cast.planeY = old_planeX * sin(-0.04) + \
					o->cast.planeY * cos(-0.04);
}

void	ft_player_rotate_l(t_info *o)
{
	double	old_planeX;
	double	old_dirX;

	old_dirX = o->cast.dirX;
	old_planeX = o->cast.planeX;
	o->cast.dirX = o->cast.dirX * cos(0.04) - \
					o->cast.dirY * sin(0.04);
	o->cast.dirY = old_dirX * sin(0.04) + \
					o->cast.dirY * cos(0.04);
	o->cast.planeX = o->cast.planeX * cos(0.04) - \
					o->cast.planeY * sin(0.04);
	o->cast.planeY = old_planeX * sin(0.04) + \
					o->cast.planeY * cos(0.04);
}

void	ft_key_action(t_info *o)
{
	if (o->k.kup)
        ft_player_forward(o);	
	if (o->k.kdown)
		ft_player_backward(o);
	if (o->k.kleft)
		ft_player_left(o);
	if (o->k.kright)
		ft_player_right(o);
	if (o->k.karr_right)
		ft_player_rotate_r(o);
	if (o->k.karr_left)
		ft_player_rotate_l(o);
	if (o->k.kesc)
		exit(0);
}