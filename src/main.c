#include "../include/cubd.h"

int	key_test(int key_code, t_info **o)
{
    if (key_code == 53)
        exit(0);
    return (0);
}

int print_background(t_info *o)
{
    int i;
    int j;

    j = -1;
    while (++j < (o->R_width / 2)) {
        i = -1;
        while (++i < o->R_height)
            mlx_pixel_put(o->mlx, o->wind, i, j, o->F);
    }
    j--;
    while (++j < o->R_width) {
        i = -1;
        while (++i < o->R_height)
            mlx_pixel_put(o->mlx, o->wind, i, j, o->C);
    }
    return (0);
}

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
			o->screen[y][x] = o->F;
			o->screen[WIN_H - y - 1][x] = o->C;
			x++;
		}
		y++;
	}
}


// int  print_one_textures(t_info *info)
// {

//     if (info->EA)
//         mlx_put_image_to_window(info->mlx, info->wind, info->EA, 100, 100);
//     return (0);
// }

int ft_game(t_info *o)
{
    ft_fill_floor_and_ceiling(o);
    wall_casting(o);
    ft_render(o);
    ft_key_action(o);
    return (0);
}

void    get_data_addr(t_info *o)
{
    o->img.img = mlx_new_image(o->mlx,WIN_W,WIN_H);
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

int main(int argc, char **argv)
{
    t_info  o;

    init_info(&o);
    o.mlx = mlx_init();
    parsing(argc, argv, &o);
    init_data(&o);
    // printf("X >> %d Y >> %d\n", o.x, o.y);
    // ft_print_darr(o.s_str, 1);
    o.mlx = mlx_init();
    o.wind = mlx_new_window(o.mlx,WIN_W, WIN_H, "Cub 3D");
    get_data_addr(&o);
    ft_import_textures(&o);
    
    

    // int i = -1;
    // while(o.s_str[++i])
    // {
    //     printf("%s\n", o.s_str[i]);
    // }


    // print_background(&o);
    // printf("H >> %d  W >>%d\n", o.R_height, o.R_width);


    // print_one_textures(&o);
    ft_game(&o);
    // mlx_hook(o.wind, 2, 1L << 0, key_test, &o);
    mlx_loop_hook(o.mlx, &ft_game, &o);
    mlx_hook(o.wind, PRESS, 0, &ft_key_press, &o);
	mlx_hook(o.wind, RELEASE, 0, &ft_key_release, &o);
	// mlx_hook(o.wind, REDCROSS, 0, ft_close_window, &o);

    mlx_loop(o.mlx);
    // mlx_destroy_window(o.mlx, o.wind);

}

//0x7ffee0fd5000