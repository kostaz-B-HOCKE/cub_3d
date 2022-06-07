#include "../include/cubd.h"

int word_add_NO(t_info *info, char **s_str)
{
    int i;

    i = -1;
    while (s_str[++i])
        ;
    if (i != 2)
        return (ft_error("bad argument.\n"));

    int	x;
    int	y;

    x = 0;
    y = 0;
//    info->NO = mlx_png_file_to_image(info->mlx,"./textures/wall.png", &x, &y);
//    printf("|1|\n");
//    info->NO = mlx_xpm_file_to_image(info->mlx, "./textures/11.xpm", &x, &i);
    info->NO = mlx_xpm_file_to_image(info->mlx, "textures/wall.xpm", &x, &y);
//    printf("|2|\n");
    return (0);
}

int word_add_SO(t_info *tmp)
{


//    printf("SO\n");
    return (0);
}

int word_add_WE(t_info *tmp)
{
//    printf("WO\n");
    return (0);
}

int word_add_EA(t_info *tmp)
{
//    printf("EA\n");
    return (0);
}
