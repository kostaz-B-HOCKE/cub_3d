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
    info->F[0] = ft_atoi(str_split[0]);
    info->F[1] = ft_atoi(str_split[1]);
    info->F[2] = ft_atoi(str_split[2]);
    ft_free_darr(str_split);
    return (0);
}

int word_add_S(t_info *info, char **s_str)
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
    info->S[0] = ft_atoi(str_split[0]);
    info->S[1] = ft_atoi(str_split[1]);
    info->S[2] = ft_atoi(str_split[2]);
    ft_free_darr(str_split);
    return (0);
}

int pars_word(char **s_str, t_info *info)
{
    if (!ft_strcmp(s_str[0], "R"))
        return (word_add_R(info, s_str));
    if (!ft_strcmp(s_str[0], "NO"))
        printf("R\n");
    if (!ft_strcmp(s_str[0], "SO"))
        printf("R\n");
    if (!ft_strcmp(s_str[0], "WE"))
        printf("R\n");
    if (!ft_strcmp(s_str[0], "EA"))
        printf("EA\n");
    if (!ft_strcmp(s_str[0], "S"))
        printf("S\n");
    if (!ft_strcmp(s_str[0], "ST"))
        printf("ST\n");
    if (!ft_strcmp(s_str[0], "FT"))
        printf("FT\n");
    if (!ft_strcmp(s_str[0], "F"))
        return (word_add_F(info, s_str));
    if (!ft_strcmp(s_str[0], "C"))
        printf("C\n");
    return (1);
}
