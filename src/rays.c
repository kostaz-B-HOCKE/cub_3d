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

	// void	ft_init_data(t_glb *glb)
	// {
	// 	glb->ctrl.key_esc = 0;
	// 	glb->ctrl.key_up = 0;
	// 	glb->ctrl.key_down = 0;
	// 	glb->ctrl.key_left = 0;
	// 	glb->ctrl.key_right = 0;
	// 	glb->speed_rotate = 0.04;
	// 	glb->speed_move = 0.04;
	// glb->player_y = (double)j + 0.5;
	// glb->player_x = (double)i + 0.5;
	// double time = 0; //time of current frame
	// double oldTime = 0; //time of previous frame
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

//эта ф-ция вызывается в цикле в get_direction()
//x-coordinate in camera space (переводим из 0..640 в -1..1)
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
