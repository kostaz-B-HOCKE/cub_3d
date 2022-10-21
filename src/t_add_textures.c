#include "../include/cubd.h"

int	word_add_R(t_info *o, char **s_str)
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

int word_add_NO(t_info *o, char **s_str)
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

int	word_add_SO(t_info *o, char **s_str)
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

int	word_add_WE(t_info *o, char **s_str)
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

int	word_add_EA(t_info *o, char **s_str)
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
	// printf("\n\nPATH %s\n\n", path);
	// if (img->img == NULL)
	// 	ft_err_exit("xpm file error");
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
										&img->len, &img->endian);
	// printf("LEN >>> %d BPP >>>> %d\n", img->len, img->bpp);
	// sleep(10);
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
