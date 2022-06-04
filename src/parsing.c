#include "../include/cubd.h"

//int check_digit(t_info *info)
//{
//    int i;
//    int j;
//
//    i = -1;
//    while (info->argv[++i])
//    {
//        j = -1;
//        while (info->argv[i][++j])
//            if (!ft_isdigit(info->argv[i][j]))  //добавить знаки
//                return (ft_error("bad argument.\n"));
//    }
//    return (0);
//}

char *association_str(char **s_str)
{
    char *str;
    int i;

    str = ft_strdup(s_str[0]);
    i = 0;
    while (s_str[++i])
        str = ft_strjoin_free_s1(str, s_str[i]);
    return (str);
}

int chek_input_values(t_info *info, int i1)
{
    int i;
    char **s_str;
    char **new_argv;
    int flag;

    i = -1;
    flag = 0;
//    ft_print_darr(info->argv, 1);
    new_argv = malloc(sizeof(char *) * 100);
    if (!new_argv)
        return (1);
    while (info->argv[++i])
    {
        s_str = ft_split(info->argv[i], ' ');
        if (!pars_word(s_str, info))
            flag = 1;
        if (flag == 1)
            new_argv[i] = association_str(s_str);
        ft_free_darr(s_str);
    }
    ft_free_darr(info->argv);
    info->argv = new_argv;
//    ft_print_darr(info->argv, 1);
    return (0);
}

int parsing(int argc, char **argv, t_info *info)
{
    int fd;
    char *str;
    int i;
    int j;

    i = 0;
    if (argc < 2)
        return (ft_error("no map specified.\n"));
    if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
        return (ft_error("invalid map.\n"));
    info->argv = malloc(sizeof(char *) * 100);
    if (!info->argv)
        return (ft_error("malloc\n"));
    j = 0;
    fd = open(argv[1], O_RDONLY);
    while ((str = get_next_line_mod(fd))) {
        if (ft_strlen(str) != 0)
            info->argv[j++] = str;
        else
            free(str);
    }
    return (chek_input_values(info, i));
}
