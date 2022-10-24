/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:36:07 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/24 16:46:03 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

void	init_pos(t_info *o, char direct, int i, int j)
{
	o->cast.poxy = (double)j;
	o->cast.posx = (double)i;
	if (direct == 'E')
	{
		o->cast.plane_x = 0.66;
		o->cast.plane_y = 0;
		o->cast.dir_x = 0;
		o->cast.dir_y = 1;
	}
	else if (direct == 'S')
	{
		o->cast.plane_x = 0;
		o->cast.plane_y = -0.66;
		o->cast.dir_x = 1;
		o->cast.dir_y = 0;
	}
	else if (direct == 'W')
	{
		o->cast.plane_x = -0.66;
		o->cast.plane_y = 0;
		o->cast.dir_x = 0;
		o->cast.dir_y = -1;
	}
}

void	get_pos(t_info *o, char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'S' \
				|| str[i][j] == 'W' || str[i][j] == 'E')
			{
				o->x = i;
				o->y = j;
				init_pos(o, str[i][j], i, j);
			}				
				j++;
		}
	}
}

void	init_data(t_info *o)
{
	t_cast	cast;

	cast.plane_x = 0;
	cast.plane_y = 0.66;
	cast.dir_x = -1;
	cast.dir_y = 0;
	o->cast = cast;
	get_pos(o, o->s_str);
}

void	get_the_angle(t_info *o)
{
	o->cast.cam_x = 2 * o->cast.wx / (double)WIN_W - 1;
	o->cast.ray_x = o->cast.dir_x + o->cast.plane_x * o->cast.cam_x;
	o->cast.ray_y = o->cast.dir_y + o->cast.plane_y * o->cast.cam_x;
	o->cast.map_x = (int)o->cast.posx;
	o->cast.map_y = (int)o->cast.poxy;
	o->cast.deltadist_x = fabs(1 / o->cast.ray_x);
	o->cast.deltadist_y = fabs(1 / o->cast.ray_y);
}
