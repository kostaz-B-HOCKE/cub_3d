/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:24:42 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/21 19:24:44 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

static int	alloc_texture_arr(t_info *o)
{
	int	i;

	o->textures = (int **)malloc(sizeof(int *) * 5);
	if (o->textures == NULL)
		ft_error("Malloc error\n");
	i = 0;
	while (i < 4)
	{
		o->textures[i] = (int *)malloc(sizeof(int) * (TEX_H * TEX_W));
		if (o->textures[i] == NULL)
			ft_error("Malloc error\n");
		i++;
	}
	o->textures[i] = NULL;
	return (0);
}

static void	ft_import_imgxpm(t_info *o, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	img->img = mlx_xpm_file_to_image(o->mlx, path, &img->img_w, &img->img_h);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
										&img->len, &img->endian);
	y = 0;
	while (y < img->img_h)
	{
		x = 0;
		while (x < img->img_w)
		{
			texture[img->img_w * y + x] = img->data[img->img_w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(o->mlx, img->img);
}

void	ft_import_textures(t_info *o)
{
	t_img	img;

	alloc_texture_arr(o);
	ft_import_imgxpm(o, o->textures[0], "./textures/bluestone.xpm", &img);
	ft_import_imgxpm(o, o->textures[1], "./textures/greystone.xpm", &img);
	ft_import_imgxpm(o, o->textures[2], "./textures/redbrick.xpm", &img);
	ft_import_imgxpm(o, o->textures[3], "./textures/wood.xpm", &img);
}
