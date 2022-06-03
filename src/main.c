#include "../include/cubd.h"
//#include "../../minilibx_mms_20200219/mlx.h"

int main(void)
{
    void *mlx;
    void *wind;

    mlx = mlx_init();
    wind = mlx_new_window(mlx, 1920, 1080, "Pom");
    mlx_loop(mlx);
    mlx_destroy_window (mlx, wind);
    printf("!");
    ft_putstr_fd("fd", 1);
}
