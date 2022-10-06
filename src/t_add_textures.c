#include "../include/cubd.h"

int word_add_R(t_info *o, char **s_str)
{
    int i;

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
    // o->NO = mlx_png_file_to_image(o->mlx,"./textures/wall.png", &x, &y);
    o->NO = mlx_xpm_file_to_image(o->mlx, "./textures/11.xpm", &x, &i);
    // o->NO = mlx_xpm_file_to_image(o->mlx, "textures/wall.xpm", &x, &y);
    return (0);
}

int word_add_SO(t_info *o, char **s_str)
{
    int i;

    i = -1;
    while (s_str[++i])
        ;
    if (i != 2)
        return (ft_error("bad argument.\n"));
    return (0);
}

int word_add_WE(t_info *o, char **s_str)
{
    int i;

    i = -1;
    while (s_str[++i])
        ;
    if (i != 2)
        return (ft_error("bad argument.\n"));
    return (0);
}

int word_add_EA(t_info *o, char **s_str)
{
    int i;

    i = -1;
    while (s_str[++i])
        ;
    if (i != 2)
        return (ft_error("bad argument.\n"));
    return (0);
}
