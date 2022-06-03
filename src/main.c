#include "../include/cubd.h"
//#include "../../minilibx_mms_20200219/mlx.h"

int main(int argc, char **argv)
{
    t_info  *info;
    void *mlx;
    void *wind;

    init_info(&info);
    if (parsing(argc, argv, info))
        return (1);




    free_info(&info);
    //    mlx = mlx_init();
//    wind = mlx_new_window(mlx, 1920, 1080, "Pom");
//    mlx_loop(mlx);
//    mlx_destroy_window (mlx, wind);
}
