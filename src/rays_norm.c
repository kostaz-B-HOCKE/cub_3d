/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:34:45 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/24 16:55:11 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

int	calc_wall_size(t_info *o, int side, int *line_height, int *start)
{
	int	end;

	if (side == 0)
		o->cast.wall_dist = (o->cast.map_x - o->cast.posx + \
								(1 - o->cast.step_x) / 2) / o->cast.ray_x;
	else
		o->cast.wall_dist = (o->cast.map_y - o->cast.poxy + \
								(1 - o->cast.step_y) / 2) / o->cast.ray_y;
	*line_height = (int)(WIN_H / o->cast.wall_dist);
	*start = -*line_height / 2 + o->r_height / 2;
	if (*start < 0)
		*start = 0;
	end = *line_height / 2 + o->r_height / 2;
	if (end >= o->r_height)
		end = o->r_height - 1;
	return (end);
}

static int	ft_choose_texture(t_info *o, int side)
{
	int	tex;

	if (side == 1 && o->cast.ray_y < 0)
		tex = 0;
	else if (side == 1 && o->cast.ray_y >= 0)
		tex = 1;
	else if (side == 0 && o->cast.ray_x < 0)
		tex = 2;
	else if (side == 0 && o->cast.ray_x >= 0)
		tex = 3;
	else
		tex = -2;
	return (tex);
}

double 	ft_choose_pixel(t_info *o, int side, int line_height, double *texture_pos, int start)
{
	double	wall_x;
	double	step;

	if (side == 0)
		wall_x = o->cast.poxy + o->cast.wall_dist * o->cast.ray_y;
	else
		wall_x = o->cast.posx + o->cast.wall_dist * o->cast.ray_x;
	wall_x = wall_x - floor(wall_x);
	o->texture_x = (int)(wall_x * (double)TEX_W);
	if (side == 0 && o->cast.ray_x > 0)
		o->texture_x = TEX_W - o->texture_x - 1;
	if (side == 1 && o->cast.ray_y < 0)
		o->texture_x = TEX_W - o->texture_x - 1;
	step = 1.0 * TEX_H / line_height;
	*texture_pos = (start - o->r_height / 2 + line_height / 2) * step;
	o->cast.wy = start;
	return (step);
}

static	void	ft_pixels_screen_buf(t_info *o, int end, double *texture_pos, double step, int side)
{
	int	color;
	int	tex;

	while (o->cast.wy < end)
	{
		o->texture_y = (int)*texture_pos & (TEX_H - 1);
		*texture_pos += step;
		tex = ft_choose_texture(o, side);
		color = o->textures[tex][TEX_H * o->texture_y + \
			o->texture_x];
		if (side == 1)
			color = (color >> 1) & 0x7F7F7F;
		o->screen[o->cast.wy][o->cast.wx] = color;
		o->cast.wy++;
	}
}

void	wall_casting(t_info *o)
{
	int		side;
	int		line_height;
	double	texture_pos;
	int		start;
	int		end;
	double	step;

	o->cast.wx = 0;
	while (o->cast.wx < WIN_W)
	{
		get_the_angle(o);
		calc_step_n_sidedist(o);
		side = dd_analyzer(o);
		end = calc_wall_size(o, side, &line_height, &start);
		step = ft_choose_pixel(o, side, line_height, &texture_pos, start);
		ft_pixels_screen_buf(o, end, &texture_pos, step, side);
		o->cast.wx++;
	}
}
