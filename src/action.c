/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:30:17 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/24 16:18:21 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

void	ft_player_forward(t_info *o)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(o->cast.posx + o->cast.dir_x * 0.04);
	nxt_y = (int)(o->cast.poxy);
	if (o->s_str[nxt_x][nxt_y] == '0')
		o->cast.posx = o->cast.posx + o->cast.dir_x * 0.04;
	nxt_x = (int)(o->cast.posx);
	nxt_y = (int)(o->cast.poxy + o->cast.dir_y * 0.04);
	if (o->s_str[nxt_x][nxt_y] == '0')
		o->cast.poxy = o->cast.poxy + o->cast.dir_y * 0.04;
}

void	ft_player_backward(t_info *o)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(o->cast.posx - o->cast.dir_x * 0.04);
	nxt_y = (int)(o->cast.poxy);
	if (o->s_str[nxt_x][nxt_y] == '0')
		o->cast.posx = o->cast.posx - o->cast.dir_x * 0.04;
	nxt_x = (int)(o->cast.posx);
	nxt_y = (int)(o->cast.poxy - o->cast.dir_y * 0.04);
	if (o->s_str[nxt_x][nxt_y] == '0')
		o->cast.poxy = o->cast.poxy - o->cast.dir_y * 0.04;
}

void	ft_player_left(t_info *o)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(o->cast.posx - o->cast.plane_x * 0.04);
	nxt_y = (int)(o->cast.poxy - o->cast.plane_y * 0.04);
	if (o->s_str[nxt_x][nxt_y] == '0')
	{
		o->cast.posx = o->cast.posx - o->cast.plane_x * 0.04;
		o->cast.poxy = o->cast.poxy - o->cast.plane_y * 0.04;
	}
}

void	ft_player_right(t_info *o)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(o->cast.posx + o->cast.plane_x * 0.04);
	nxt_y = (int)(o->cast.poxy + o->cast.plane_y * 0.04);
	if (o->s_str[nxt_x][nxt_y] == '0')
	{
		o->cast.posx = o->cast.posx + o->cast.plane_x * 0.04;
		o->cast.poxy = o->cast.poxy + o->cast.plane_y * 0.04;
	}
}
