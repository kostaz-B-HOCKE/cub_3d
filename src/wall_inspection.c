#include "../include/cubd.h"

int offset_7(t_info *o)
{
    if (o->argv[o->y - 1][o->x -1] && o->argv[o->y - 1][o->x - 1] == '1' && o->check[o->y - 1][o->x -1] != 'W')
        return (1);
    return (0);
}

int offset_8(t_info *o)
{
    if (o->argv[o->y - 1][o->x] && o->argv[o->y - 1][o->x] == '1' && o->check[o->y - 1][o->x] != 'W')
        return (1);
    return (0);
}

int offset_9(t_info *o)
{
    if (o->argv[o->y - 1][o->x + 1] && o->argv[o->y - 1][o->x + 1] == '1' && o->check[o->y - 1][o->x + 1] != 'W')
        return (1);
    return (0);
}

int offset_6(t_info *o)
{
    if (o->argv[o->y][o->x + 1] && o->argv[o->y][o->x + 1] == '1' && o->check[o->y][o->x + 1] != 'W')
        return (1);
    return (0);
}

int offset_3(t_info *o)
{
    if (o->argv[o->y + 1][o->x + 1] && o->argv[o->y + 1][o->x + 1] == '1' && o->check[o->y + 1][o->x + 1] != 'W')
        return (1);
    return (0);
}

int offset_2(t_info *o)
{
    if (o->argv[o->y + 1][o->x] && o->argv[o->y + 1][o->x] == '1' && o->check[o->y + 1][o->x] != 'W')
        return (1);
    return (0);
}

int offset_1(t_info *o)
{
    if (o->argv[o->y + 1][o->x - 1] && o->argv[o->y + 1][o->x - 1] == '1' && o->check[o->y + 1][o->x - 1] != 'W')
        return (1);
    return (0);
}

int offset_4(t_info *o)
{
    if (o->argv[o->y][o->x - 1] && o->argv[o->y][o->x - 1] == '1' && o->check[o->y][o->x - 1] != 'W')
        return (1);
    return (0);
}

int offset_5(t_info *o)
{
    if (o->argv[o->y][o->x] && o->argv[o->y][o->x] == '1' && o->check[o->y][o->x] != 'W')
        return (1);
    return (0);
}

int cheak_plaer(t_info *info)
{
    int i;
    int j;
    int flag;

    i = -1;
    flag = 0;
    while (info->argv[++i])
    {
        j = -1;
        while (info->argv[i][++j])
            if (info->argv[i][j] == 'N')
                flag++;
    }
    if (flag != 1)
        return (ft_error("bad argument.\n"));
    return (0);
}

//int look_left_unit(t_info *o)
int look_top_left(t_info *o)
{
    int flag;

    flag = 0;
    if (o->argv[o->y - 1][o->x + 1] && o->argv[o->y - 1][o->x + 1] == '1' && o->check[o->y - 1][o->x + 1] != 'W')
        flag = 1;
    if (o->argv[o->y - 1][o->x] && o->argv[o->y - 1][o->x] == '1' && o->check[o->y - 1][o->x] != 'W' && flag != 1) {
        o->y--;
        o->check[o->y][o->x] = 'W';
        return (1);
    }
    else if (o->argv[o->y - 1][o->x -1] && o->argv[o->y - 1][o->x - 1] == '1' && o->check[o->y - 1][o->x -1] != 'W' && flag != 1)
    {
        o->x--;
        o->y--;
        o->check[o->y][o->x] = 'W';
        return (1);
    }
    if (flag == 1)
        return (2);
    return (0);
}

int look_top_right(t_info *o)
{
    int flag;

    flag = 0;
    if (o->argv[o->y + 1][o->x + 1] && o->argv[o->y + 1][o->x + 1] == '1' && o->check[o->y + 1][o->x + 1] != 'W')
        flag = 1;
    if (o->argv[o->y][o->x + 1] && o->argv[o->y][o->x + 1] == '1' && o->check[o->y][o->x + 1] != 'W' && flag != 1)
    {
        o->x++;
        o->check[o->y][o->x] = 'W';
        return (1);
    }
    else if (o->argv[o->y - 1][o->x + 1] && o->argv[o->y - 1][o->x + 1] == '1' && o->check[o->y - 1][o->x + 1] != 'W' && flag != 1)
    {
        o->y--;
        o->x++;
        o->check[o->y][o->x] = 'W';
        return (1);
    }
    if (flag == 1)
        return (2);
    return (0);
}

int look_low_right(t_info *o)
{
    if (o->argv[o->y + 1][o->x] && o->argv[o->y + 1][o->x] == '1' && o->check[o->y + 1][o->x] != 'W')
    {
        o->y++;
        o->check[o->y][o->x] = 'W';
        return (1);
    }
    if (o->argv[o->y + 1][o->x + 1] && o->argv[o->y + 1][o->x + 1] == '1' && o->check[o->y + 1][o->x + 1] != 'W')
    {
        o->y++;
        o->x++;
        o->check[o->y][o->x] = 'W';
        return (1);
    }
    return (0);
}

int look_low_left(t_info *o)
{
    if (o->argv[o->y][o->x - 1] && o->argv[o->y][o->x - 1] == '1' && o->check[o->y][o->x - 1] != 'W')
    {
        o->x--;
        o->check[o->y][o->x] = 'W';
        return (1);
    }
    else if (o->argv[o->y + 1][o->x - 1] && o->argv[o->y + 1][o->x - 1] == '1' && o->check[o->y + 1][o->x - 1] != 'W')
    {
        o->x--;
        o->y++;
        o->check[o->y][o->x] = 'W';
        return (1);
    }
    return (0);
}

int look_top_while(t_info *o)
{
    int i;

    o->x--;
    i = look_top_left(o);
    while (i == 1)
        i = look_top_left(o);
//    while (i == 1)
//        i = look_top_right(o);
    printf("%d\n", i);
    ft_print_darr(o->check, 1);
    return (0);
}

//далее название *info сокращено до *o что было более читаемо
void    check_wall(t_info *o)
{
    o->check = ft_strdup_two(o->argv);
//    ft_print_darr(o->check, 1);
    while (o->argv[++o->y])
    {
        o->x = -1;
        while (o->argv[o->y][++o->x])
            if (o->argv[o->y][o->x] == 'N')
            {
//                o->check[o->y][o->x] = '9';
//                look_left_unit(o);
                o->check[o->y][o->x] = 'W';
                look_top_while(o);
//                look_top_unit(o);
                return ;
            }
    }
}

int wall_inspection(t_info *info)
{
    int i;

//    printf("'/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/''/'\n");
    cheak_plaer(info);
    check_wall(info);

    return (0);
}
