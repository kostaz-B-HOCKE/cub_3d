#include "../include/cubd.h"
//#include "../../minilibx_mms_20200219/mlx.h"

int	key_test(int key_code, t_info **info)
{
    if (key_code == 53)
        exit(0);
    return (0);
}

int print_background(t_info *info)
{
    int i;
    int j;

    j = -1;
    while (++j < (info->width / 2)) {
        i = -1;
        while (++i < info->height)
            mlx_pixel_put(info->mlx, info->wind, i, j, info->F);
    }
    j--;
    while (++j < info->width) {
        i = -1;
        while (++i < info->height)
            mlx_pixel_put(info->mlx, info->wind, i, j, info->C);
    }
    return (0);
}

int  print_one_textures(t_info *info)
{


    mlx_put_image_to_window(info->mlx, info->wind, info->NO, 50, 50);
    return (0);
}

int main(int argc, char **argv)
{
    t_info  info;

    init_info(&info);
    printf("'11111111/'\n");
    info.mlx = mlx_init();
    printf("22222222222'/''/''/''/''/''/'\n");
    parsing(argc, argv, &info);
    printf("'/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/'\n");
//    ft_print_darr(info.argv, 1);

//    info.mlx = mlx_init();
    info.wind = mlx_new_window(info.mlx, info.height, info.width, "Cub 3D");
    mlx_hook(info.wind, 2, 1L << 0, key_test, &info);

//    mlx_put_image_to_window(info.mlx, info.wind, info.NO, 50, 50);
    print_background(&info);
    print_one_textures(&info);

    mlx_loop(info.mlx);
    mlx_destroy_window (info.mlx, info.wind);
}

