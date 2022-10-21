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
            if (!ft_isdigit(argv[i][j]) && argv[i][j] != 'S' && argv[i][j] != 'N' && argv[i][j] != ' ' && argv[i][j] != 'W' && argv[i][j] != 'E')  //добавить знаки
            {
                printf("c:%c\n", argv[i][j]);
                return (ft_error("bad argument.\n"));
            }
    }
    return (0);
}

int     association_str(char **s_str)
{
    int color;

    color = ft_atoi(s_str[0]);
    color = color + ft_atoi(s_str[1]) * 255;
    color = color + ft_atoi(s_str[2]) * 255 * 255;
    return (color);
}
// int chek_input_values(t_info *info, int i1)
// {
//     int i;
//     char **s_str;
//     char **new_argv;
//     int flag;
//     char *str;

//     i = -1;
// //    ft_print_darr(info->argv, 1);
//     while (info->argv[++i])
//         ;
//     new_argv = malloc(sizeof(char *) * i);
//     if (!new_argv)
//         exit(1);
//     flag = 0;
//     i = -1;
//     while (info->argv[++i] && ft_strlen(info->argv[i]) != 0)
//     {
//         s_str = ft_split(info->argv[i], ' ');
//         if (flag == 0 && pars_word(s_str, info)) {
//             flag = i;
//         }
//         if (flag != 0)
//         {
//             check_digit_arr(s_str);
//             str = association_str(s_str);
//             if (str)
//                 new_argv[i - flag] = str;
//             new_argv[(i - flag + 1)] = 0;
//         }
//         ft_free_darr(s_str);
//     }
//     ft_free_darr(info->argv);
//     info->argv = new_argv;
//     return (wall_inspection(info));
// }

void    construct_str(char *filename, t_info *o)
{
    char *lane;
    int i;
    int fd;
    char **s_str;

    i = 0;
    fd = open(filename, O_RDONLY);
    while((lane = get_next_line(fd)))
    {
        if (ft_strlen(lane))
            i++;
        free(lane);
    }
    o->s_str = (char **)malloc(sizeof(char *) * (i + 1));
    if (!o->s_str)
        ft_error("malloc error\n");
    i = -1;
    fd = open(filename, O_RDONLY);
    while((lane = get_next_line(fd)))
        if (ft_strlen(lane))
            o->s_str[++i] = lane;
    o->s_str[++i] = 0;
}

int start_sim(char c)
{
    if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (1);
    return (0);
}

void chek_zero(t_info *o)
{

    if (!(o->s_str[o->y][(o->x + 1)] && start_sim(o->s_str[o->y][(o->x + 1)])) || 
    !(o->s_str[o->y][(o->x - 1)] && start_sim(o->s_str[o->y][(o->x - 1)])) || 
    !(o->s_str[o->y + 1][o->x] && start_sim(o->s_str[o->y + 1][o->x])) ||
    !(o->s_str[o->y - 1][(o->x)] && start_sim(o->s_str[o->y - 1][(o->x)])))
        ft_error("bad mapw");                  
}

int cheak_plaer(t_info *o)
{
    int i;
    int j;
    int flag;

    i = -1;
    flag = 0;
    while (o->s_str[++i])
    {
        j = -1;
        while (o->s_str[i][++j])
            if (o->s_str[i][j] == 'N' || o->s_str[i][j] == 'W' || o->s_str[i][j] == 'E' || o->s_str[i][j] == 'S')
            {
                flag++;
                o->y = i;
                o->x = j;
            }
    }
    // printf("X >> %d Y >> %d\n", o->x, o->y);
    if (flag != 1)
        return (ft_error("bad argument..\n"));
    return (0);
}

void    closed_walls(t_info *o)
{
    int i;
    int j;

    o->y = -1;
    while (o->s_str[++(o->y)])
    {
        o->x = -1;
        while (o->s_str[o->y][++(o->x)])
            if (o->s_str[o->y][(o->x)] == '0' || o->s_str[o->y][(o->x)] == 'N' || o->s_str[o->y][(o->x)] == 'W' || o->s_str[o->y][(o->x)] == 'E' || o->s_str[o->y][(o->x)] == 'S')
                chek_zero(o);
    }
    check_digit_arr(o->s_str);
    cheak_plaer(o);
}

void    construct_argv(char *filename, t_info *o)
{
    int ch_len;
    // int len;
    char *lane;
    int fd;
    // int count;

    // len = 0;
    // count = 0;
    construct_str(filename, o);
    cheak_first_word(o);
    closed_walls(o);
}

int parsing(int argc, char **argv, t_info *o)
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
    construct_argv(argv[1], o);
    return (0);
}

