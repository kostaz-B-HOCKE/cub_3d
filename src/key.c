/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:33:49 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/24 16:21:35 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

int	ft_key_press(int key, t_info *o)
{
	if (key == ESC)
		exit(0);
	else if (key == UP)
		o->k.kup = 1;
	else if (key == LEFT)
		o->k.kleft = 1;
	else if (key == DOWN)
		o->k.kdown = 1;
	else if (key == RIGHT)
		o->k.kright = 1;
	else if (key == ARROW_RIGHT)
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
	else if (key == ARROW_RIGHT)
		o->k.karr_right = 0;
	else if (key == ARROW_LEFT)
		o->k.karr_left = 0;
	return (0);
}

void	ft_player_rotate_r(t_info *o)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = o->cast.dir_x;
	old_plane_x = o->cast.plane_x;
	o->cast.dir_x = o->cast.dir_x * cos(-0.04) - \
					o->cast.dir_y * sin(-0.04);
	o->cast.dir_y = old_dir_x * sin(-0.04) + \
					o->cast.dir_y * cos(-0.04);
	o->cast.plane_x = o->cast.plane_x * cos(-0.04) - \
					o->cast.plane_y * sin(-0.04);
	o->cast.plane_y = old_plane_x * sin(-0.04) + \
					o->cast.plane_y * cos(-0.04);
}

void	ft_player_rotate_l(t_info *o)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = o->cast.dir_x;
	old_plane_x = o->cast.plane_x;
	o->cast.dir_x = o->cast.dir_x * cos(0.04) - \
					o->cast.dir_y * sin(0.04);
	o->cast.dir_y = old_dir_x * sin(0.04) + \
					o->cast.dir_y * cos(0.04);
	o->cast.plane_x = o->cast.plane_x * cos(0.04) - \
					o->cast.plane_y * sin(0.04);
	o->cast.plane_y = old_plane_x * sin(0.04) + \
					o->cast.plane_y * cos(0.04);
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
