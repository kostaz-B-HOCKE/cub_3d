/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_norm2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:38:23 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/24 16:46:05 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

void	calc_step_n_sidedist(t_info	*o)
{
	if (o->cast.ray_x < 0)
	{
		o->cast.step_x = -1;
		o->cast.sidedist_x = (o->cast.posx - o->cast.map_x) * \
			o->cast.deltadist_x;
	}
	else
	{
		o->cast.step_x = 1;
		o->cast.sidedist_x = (o->cast.map_x + 1.0 - o->cast.posx) * \
			o->cast.deltadist_x;
	}
	if (o->cast.ray_y < 0)
	{
		o->cast.step_y = -1;
		o->cast.sidedist_y = (o->cast.poxy - o->cast.map_y) * \
			o->cast.deltadist_y;
	}
	else
	{
		o->cast.step_y = 1;
		o->cast.sidedist_y = (o->cast.map_y + 1.0 - o->cast.poxy) * \
			o->cast.deltadist_y;
	}
}

int	dd_analyzer(t_info *o)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (o->cast.sidedist_x < o->cast.sidedist_y)
		{
			o->cast.sidedist_x = o->cast.sidedist_x + o->cast.deltadist_x;
			o->cast.map_x = o->cast.map_x + o->cast.step_x;
			side = 0;
		}
		else
		{
			o->cast.sidedist_y = o->cast.sidedist_y + o->cast.deltadist_y;
			o->cast.map_y = o->cast.map_y + o->cast.step_y;
			side = 1;
		}
		if (o->s_str[o->cast.map_x][o->cast.map_y] == '1')
			hit = 1;
	}
	return (side);
}

void	ft_render(t_info *o)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			o->img.data[y * WIN_W + x] = o->screen[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(o->mlx, o->wind, o->img.img, 0, 0);
}
