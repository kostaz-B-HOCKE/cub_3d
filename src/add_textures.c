#include "../include/cubd.h"

int word_add_NO(t_info *tmp, char **s_str)
{
    int i;

    i = -1;
    while (s_str[++i])
        ;
    if (i != 2)
        return (ft_error("bad argument.\n"));


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
