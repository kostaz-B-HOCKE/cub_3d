/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:24:52 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/24 16:51:03 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

void	ft_fill_floor_and_ceiling(t_info *o)
{
	int	y;
	int	x;

	y = WIN_H / 2 + 1;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			o->screen[y][x] = o->fff;
			o->screen[WIN_H - y - 1][x] = o->ccc;
			x++;
		}
		y++;
	}
}

int	ft_game(t_info *o)
{
	ft_fill_floor_and_ceiling(o);
	wall_casting(o);
	ft_render(o);
	ft_key_action(o);
	return (0);
}

void	get_data_addr(t_info *o)
{
	o->img.img = mlx_new_image(o->mlx, WIN_W, WIN_H);
	o->img.data = (int *)mlx_get_data_addr(o->img.img, &o->img.bpp, \
					&o->img.len, &o->img.endian);
}

int	ft_close_window(t_info *o)
{
	if (o->mlx != 0)
	{
		mlx_clear_window(o->mlx, o->wind);
		mlx_destroy_window(o->mlx, o->wind);
	}
	exit (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	o;

	init_info(&o);
	o.mlx = mlx_init();
	parsing(argc, argv, &o);
	init_data(&o);
	o.mlx = mlx_init();
	o.wind = mlx_new_window(o.mlx, WIN_W, WIN_H, "Cub 3D");
	get_data_addr(&o);
	ft_import_textures(&o);
	ft_game(&o);
	mlx_loop_hook(o.mlx, &ft_game, &o);
	mlx_hook(o.wind, PRESS, 0, &ft_key_press, &o);
	mlx_hook(o.wind, RELEASE, 0, &ft_key_release, &o);
	mlx_hook(o.wind, REDCROSS, 0, ft_close_window, &o);
	mlx_loop(o.mlx);
	return (0);
}
