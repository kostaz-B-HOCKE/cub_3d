#include "../include/cubd.h"

void	ft_player_forward(t_info *o)
{
	int nxt_x;
	int nxt_y;

	nxt_x = (int)(o->cast.posX + o->cast.dirX * 0.04);
	nxt_y = (int)(o->cast.posY);
	if (o->s_str[nxt_x][nxt_y] == '0')
		o->cast.posX = o->cast.posX + o->cast.dirX * 0.04;
	nxt_x = (int)(o->cast.posX);
	nxt_y = (int)(o->cast.posY + o->cast.dirY * 0.04);
	if (o->s_str[nxt_x][nxt_y] == '0')
		o->cast.posY = o->cast.posY + o->cast.dirY * 0.04;
    printf("NXT_X %d\n", nxt_x);
}

void	ft_player_backward(t_info *o)
{
	int nxt_x;
	int nxt_y;

	nxt_x = (int)(o->cast.posX - o->cast.dirX * 0.04);
	nxt_y = (int)(o->cast.posY);
	if (o->s_str[nxt_x][nxt_y] == '0')
		o->cast.posX = o->cast.posX - o->cast.dirX * 0.04;
	nxt_x = (int)(o->cast.posX);
	nxt_y = (int)(o->cast.posY - o->cast.dirY * 0.04);
	if (o->s_str[nxt_x][nxt_y] == '0')
		o->cast.posY = o->cast.posY - o->cast.dirY * 0.04;
}

void	ft_player_left(t_info *o)
{
	int nxt_x;
	int nxt_y;

	nxt_x = (int)(o->cast.posX - o->cast.planeX * 0.04);
	nxt_y = (int)(o->cast.posY - o->cast.planeY * 0.04);
	if (o->s_str[nxt_x][nxt_y] == '0')
	{
		o->cast.posX = o->cast.posX - o->cast.planeX * 0.04;
		o->cast.posY = o->cast.posY - o->cast.planeY * 0.04;
	}
}

void	ft_player_right(t_info *o)
{
	int nxt_x;
	int nxt_y;

	nxt_x = (int)(o->cast.posX + o->cast.planeX * 0.04);
	nxt_y = (int)(o->cast.posY + o->cast.planeY * 0.04);
	if (o->s_str[nxt_x][nxt_y] == '0')
	{
		o->cast.posX = o->cast.posX + o->cast.planeX * 0.04;
		o->cast.posY = o->cast.posY + o->cast.planeY * 0.04;
	}
}