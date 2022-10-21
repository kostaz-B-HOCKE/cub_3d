/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_add_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:23:51 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/21 19:26:23 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

int	word_add_r(t_info *o, char **s_str)
{
	int	i;

	i = 0;
	while (s_str[i++])
		;
	if (i != 4)
		return (ft_error("bad argument.\n"));
	if (check_digit_str(s_str[1]) || check_digit_str(s_str[2]))
		return (ft_error("bad argument.\n"));
	o->R_height = ft_atoi(s_str[1]);
	o->R_width = ft_atoi(s_str[2]);
	return (0);
}

int	word_add_no(t_info *o, char **s_str)
{
	int	x;
	int	y;

	y = -1;
	while (s_str[++y])
		;
	if (y != 2)
		return (ft_error("bad argument.\n"));
	o->NO = mlx_xpm_file_to_image(o->mlx, "textures/bluestone.xpm", &x, &y);
	return (0);
}

int	word_add_so(t_info *o, char **s_str)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (s_str[++i])
		;
	if (i != 2)
		return (ft_error("bad argument.\n"));
	o->SO = mlx_xpm_file_to_image(o->mlx, "./textures/greystone.xpm", &x, &y);
	return (0);
}

int	word_add_we(t_info *o, char **s_str)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (s_str[++i])
		;
	if (i != 2)
		return (ft_error("bad argument.\n"));
	o->WE = mlx_xpm_file_to_image(o->mlx, "./textures/wall.xpm", &x, &y);
	return (0);
}

int	word_add_ea(t_info *o, char **s_str)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (s_str[++i])
		;
	if (i != 2)
		return (ft_error("bad argument.\n"));
	o->EA = mlx_xpm_file_to_image(o->mlx, "./textures/wood.xpm", &x, &y);
	return (0);
}
