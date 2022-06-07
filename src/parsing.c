#include "../include/cubd.h"

int check_digit_arr(char **argv)
{
    int i;
    int j;

    i = -1;
    while (argv[++i])
    {
        j = -1;
        while (argv[i][++j])
            if (!ft_isdigit(argv[i][j]) && argv[i][j] != 'S' && argv[i][j] != 'N')  //добавить знаки
            {
                printf("c:%c\n", argv[i][j]);
                return (ft_error("bad argument.\n"));
            }
    }
    return (0);
}

char *association_str(char **s_str)
{
    char *str;
    int i;
    int j;

    if (s_str) {
        j = -1;
        str = ft_strdup(s_str[0]);
        i = 0;
        while (s_str[++i])
            str = ft_strjoin_free_s1(str, s_str[i]);
        return (str);
    }
    return (0);
}

int chek_input_values(t_info *info, int i1)
{
    int i;
    char **s_str;
    char **new_argv;
    int flag;
    char *str;

    i = -1;
//    ft_print_darr(info->argv, 1);
    while (info->argv[++i])
        ;
    new_argv = malloc(sizeof(char *) * i);
    if (!new_argv)
        exit(1);
    flag = 0;
    i = -1;
    while (info->argv[++i] && ft_strlen(info->argv[i]) != 0)
    {
        s_str = ft_split(info->argv[i], ' ');
        if (flag == 0 && pars_word(s_str, info)) {
            flag = i;
        }
        if (flag != 0)
        {
            check_digit_arr(s_str);
            str = association_str(s_str);
            if (str)
                new_argv[i - flag] = str;
            new_argv[(i - flag + 1)] = 0;
        }
        ft_free_darr(s_str);
    }
    ft_free_darr(info->argv);
    info->argv = new_argv;
//    ft_print_darr(info->argv, 1);
    return (wall_inspection(info));
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
    info->argv = malloc(sizeof(char *) * 300);
    if (!info->argv)
        return (ft_error("malloc\n"));
    j = 0;
    fd = open(argv[1], O_RDONLY);
    while ((str = get_next_line_mod(fd)))
    {
        if (ft_strlen(str) != 0)
            info->argv[j++] = str;
        else
            free(str);
    }
    info->argv[j] = 0;
    return (chek_input_values(info, i));
}
