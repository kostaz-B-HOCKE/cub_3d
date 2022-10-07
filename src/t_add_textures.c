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
    char *tmp;
    int	x;
    int	y;

    y = -1;
    while (s_str[++y])
        ;
    if (y != 2)
        return (ft_error("bad argument.\n"));
    x = TEX_W;
    y = TEX_H;
    tmp = (char *)o->NO;
    // if (-1 == open(tmp, O_))
    //     ft_error("no textures");
    o->NO = mlx_xpm_file_to_image(o->mlx, tmp, &x, &y);
    free(tmp);
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
