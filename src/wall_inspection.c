#include "../include/cubd.h"

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
            if (info->argv[i][j] == 'S')
                flag++;
    }
    if (flag != 1)
        return (ft_error("bad argument.\n"));
    return (0);
}


int wall_inspection(t_info *info)
{
    int i;

    cheak_plaer(info);


    return (0);
}
