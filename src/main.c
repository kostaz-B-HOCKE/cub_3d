#include "../include/cubd.h"
//#include "../../minilibx_mms_20200219/mlx.h"

int main(int argc, char **argv)
{
    t_info  *info;
    void *mlx;
    void *wind;

    init_info(&info);
    parsing(argc, argv, info);
//    printf("free\n");
//    free_info(&info);
    mlx = mlx_init();
    wind = mlx_new_window(mlx, info->height, info->width, "Pom");
    mlx_loop(mlx);
    mlx_destroy_window (mlx, wind);
}
