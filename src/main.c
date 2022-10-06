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

int  print_one_textures(t_info *info)
{

    if (info->NO)
        mlx_put_image_to_window(info->mlx, info->wind, info->NO, 50, 50);
    return (0);
}

int main(int argc, char **argv)
{
    t_info  o;

    init_info(&o);
    o.mlx = mlx_init();
    parsing(argc, argv, &o);
    ft_print_darr(o.argv, 1);
    printf("git \n")
    // o.mlx = mlx_init();
    // o.wind = mlx_new_window(o.mlx, o.R_height, o.R_width, "Cub 3D");
    // mlx_hook(o.wind, 2, 1L << 0, key_test, &o);
    // print_background(&o);
//    print_one_textures(&o);

//    mlx_loop(o.mlx);
//    mlx_destroy_window(o.mlx, o.wind);
}
