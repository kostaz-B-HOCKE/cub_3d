#include "../include/cubd.h"
//#include "../../minilibx_mms_20200219/mlx.h"

int	key_test(int key_code, t_info **info)
{
    if (key_code == 53)
        exit(0);
    return (0);
}

int main(int argc, char **argv)
{
    t_info  info;
    void *mlx;
    void *wind;

    init_info(&info);
    parsing(argc, argv, &info);
    printf("'/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/'\n");
    ft_print_darr(info.argv, 1);


    info.mlx = mlx_init();
    info.wind = mlx_new_window(info.mlx, info.height, info.width, "Pom");
    mlx_hook(info.wind, 2, 1L << 0, key_test, &info);
    mlx_loop(info.mlx);
    mlx_destroy_window (info.mlx, info.wind);
}
