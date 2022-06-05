#include "../include/cubd.h"

int word_add_R(t_info *info, char **s_str)
{
    int i;

    i = 0;
    while (s_str[i++])
        ;
    if (i != 4)
        return (ft_error("bad argument.\n"));
    if (check_digit_str(s_str[1]) || check_digit_str(s_str[2]))
        return (ft_error("bad argument.\n"));
    info->height = ft_atoi(s_str[1]);
    info->width = ft_atoi(s_str[2]);
    return (0);
}

int word_add_F(t_info *info, char **s_str)
{
    int i;
    char **str_split;

    i = 0;
    while (s_str[i++])
        ;
    if (i != 3)
        return (ft_error("bad argument.\n"));
    str_split = ft_split(s_str[1], ',');
    if (check_digit_str(str_split[0]) || check_digit_str(str_split[1]) || check_digit_str(str_split[2]))
        return (ft_error("bad argument.\n"));
    info->F = ft_atoi(association_str(str_split));
    ft_free_darr(str_split);
    return (0);
}

int word_add_C(t_info *info, char **s_str)
{
    int i;
    char **str_split;

    i = 0;
    while (s_str[i++])
        ;
    if (i != 3)
        return (ft_error("bad argument.\n"));
    str_split = ft_split(s_str[1], ',');
    if (check_digit_str(str_split[0]) || check_digit_str(str_split[1]) || check_digit_str(str_split[2]))
        return (ft_error("bad argument.\n"));
    info->C = ft_atoi(association_str(str_split));
    ft_free_darr(str_split);
    return (0);
}

int pars_word(char **s_str, t_info *info)
{
    if (!ft_strcmp(s_str[0], "R"))
        return (word_add_R(info, s_str));
    if (!ft_strcmp(s_str[0], "NO"))
        return (word_add_NO(info, s_str));
    if (!ft_strcmp(s_str[0], "SO"))
        return (word_add_SO(info));
    if (!ft_strcmp(s_str[0], "WE"))
        return (word_add_WE(info));
    if (!ft_strcmp(s_str[0], "EA"))
        return (word_add_EA(info));
    if (!ft_strcmp(s_str[0], "S"))
        return (0);
    if (!ft_strcmp(s_str[0], "ST"))
        return (0);
    if (!ft_strcmp(s_str[0], "FT"))
        return (0);
    if (!ft_strcmp(s_str[0], "F"))
        return (word_add_F(info, s_str));
    if (!ft_strcmp(s_str[0], "C"))
        return (word_add_C(info, s_str));
    return (1);
}
