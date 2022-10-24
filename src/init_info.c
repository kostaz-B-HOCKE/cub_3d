/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:32:57 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/24 16:50:37 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

void	init_info(t_info *new)
{
	new->argv = NULL;
	new->ccc = 0;
	new->fff = 0;
	new->mlx = NULL;
	new->s_str = NULL;
	new->x = 0;
	new->y = 0;
	new->fd = 0;
	new->r_width = WIN_W;
	new->r_height = WIN_H;
}

//не поместилось по норме
int	print_background(t_info *o)
{
	int	i;
	int	j;

	j = -1;
	while (++j < (o->r_width / 2))
	{
		i = -1;
		while (++i < o->r_height)
			mlx_pixel_put(o->mlx, o->wind, i, j, o->fff);
	}
	j--;
	while (++j < o->r_width)
	{
		i = -1;
		while (++i < o->r_height)
			mlx_pixel_put(o->mlx, o->wind, i, j, o->ccc);
	}
	return (0);
}
