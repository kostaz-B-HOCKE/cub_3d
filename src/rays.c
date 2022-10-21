#include "../include/cubd.h"

	// void	ft_init_data(t_glb *glb)
	// {
	// 	glb->ctrl.key_esc = 0;
	// 	glb->ctrl.key_up = 0;
	// 	glb->ctrl.key_down = 0;
	// 	glb->ctrl.key_left = 0;
	// 	glb->ctrl.key_right = 0;
	// 	glb->speed_rotate = 0.04;
	// 	glb->speed_move = 0.04;
	// glb->player_y = (double)j + 0.5;
	// glb->player_x = (double)i + 0.5;
	// double time = 0; //time of current frame
	// double oldTime = 0; //time of previous frame

void	init_pos(t_info *o, char direct, int i, int j)
{
	o->cast.posY = (double)j;//+0.5
	o->cast.posX = (double)i;//+0.5
	// printf("PLAYER X %f PLAYER Y %f\n",o->cast.posX, o->cast.posY);
	if (direct == 'E')
	{
		o->cast.planeX = 0.66;
		o->cast.planeY = 0;
		o->cast.dirX = 0;
		o->cast.dirY = 1;
	}
	else if (direct == 'S')
	{
		o->cast.planeX = 0;
		o->cast.planeY = -0.66;
		o->cast.dirX = 1;
		o->cast.dirY = 0;
	}
	else if (direct == 'W')
	{
		o->cast.planeX = -0.66;
		o->cast.planeY = 0;
		o->cast.dirX = 0;
		o->cast.dirY = -1;
	}
	// printf("CamPlaneX >> %f CamPlaneY >> %f\n", o->cast.planeX, o->cast.planeY);
	// printf("PLAYERDirX   >> %f PLAYERDirY   >> %f\n",  o->cast.dirX, o->cast.dirY);
}

void get_pos(t_info *o, char **str)
{
	int i;
	int j;

	// printf("STRRRRR %s\n", str[0]);
	i = -1;
	while (str[++i])
	{
		// printf("STR %s\n", str[i]);
		j = 0;
		while (str[i][j])
			{
				if (str[i][j] == 'N' || str[i][j] == 'S'\
					|| str[i][j] == 'W' || str[i][j] == 'E')
					{
						o->x = i;
						o->y = j;
						init_pos(o, str[i][j], i, j);
					}
					
				j++;
			}
			
	}
	// printf("X >> %d Y >> %d\n", o->x, o->y);
}


void init_data(t_info *o)
{
	t_cast cast;

	// cast.posX = 1 + 0.5;//(double)o->x; Позиция игрока на карте + 0,5 
	// // printf("!!!!%d\n", o->x);
	// cast.posY = 1 + 0.5;//(double)o->y; Позиция игрока на карте + 0,5
	cast.planeX = 0;
	cast.planeY = 0.66; //the 2d raycaster version of camera plane
	cast.dirX = -1;
	cast.dirY = 0; //initial direction vector
	o->cast = cast;
	get_pos(o, o->s_str);
}

void    get_the_angle(t_info *o)//эта ф-ция вызывается в цикле в get_direction()
{   
	//calculate ray position and direction
	o->cast.camX = 2 * o->cast.wx / (double)WIN_W  - 1; //x-coordinate in camera space (переводим из 0..640 в -1..1)
	// printf("%f\n", o->cast.camX);
	o->cast.rayX = o->cast.dirX + o->cast.planeX * o->cast.camX;//(-1 + 0*(-1..1))
	// printf("%f\n", o->cast.rayX);
	o->cast.rayY = o->cast.dirY + o->cast.planeY * o->cast.camX;//0+0.66*(-1..1)
	// printf("%f\n", o->cast.rayY);
	o->cast.mapX = (int)o->cast.posX;
	// printf("MApX %d\n", o->cast.mapX);
	o->cast.mapY = (int)o->cast.posY;
	// printf("MApY %d\n", o->cast.mapY);
	o->cast.deltaDistX = fabs(1 / o->cast.rayX);
	// printf("DeltaDistX  %f\n", o->cast.deltaDistX);
	o->cast.deltaDistY = fabs(1 / o->cast.rayY);
	// printf("DeltaDistY  %f\n", o->cast.deltaDistY);
	// sleep(5);
}

void	calc_step_n_sideDist(t_info *o)// вычисляем шаг и начальное значение sideDist
{
	if (o->cast.rayX < 0)
	{
		o->cast.stepX = -1;
		o->cast.sideDistX = (o->cast.posX - o->cast.mapX) * o->cast.deltaDistX;
		// printf("1 sideDistX  %f\n", o->cast.sideDistX );
	}
	else
	{
		o->cast.stepX = 1;
		o->cast.sideDistX = (o->cast.mapX + 1.0 - o->cast.posX) * o->cast.deltaDistX;
		// printf("2 sideDistX  %f\n", o->cast.sideDistX );
	}
	if  (o->cast.rayY < 0)
	{
		o->cast.stepY = -1;
		o->cast.sideDistY = (o->cast.posY - o->cast.mapY) * o->cast.deltaDistY;
		// printf("3 sideDistY  %f\n", o->cast.sideDistY );
	}
	else
	{
		o->cast.stepY = 1;
		o->cast.sideDistY = (o->cast.mapY + 1.0 - o->cast.posY) * o->cast.deltaDistY;
		// printf("4 sideDistY  %f\n", o->cast.sideDistY );
	}
	// sleep(5);
}

int	dd_analyzer(t_info *o)//Digital Differential Analyzer
/* Когда луч попадает в стену, цикл завершается, 
и переменная side показыввает сторону стены (сторона х или сторона у), куда ударил луч
и координаты стены (mapX и mapY) */
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		// printf("o->cast.mapX >> %d  o->cast.mapY%d",o->cast.mapX,o->cast.mapY);
		if (o->cast.sideDistX < o->cast.sideDistY)
		{
			o->cast.sideDistX = o->cast.sideDistX + o->cast.deltaDistX;
			// printf("1 sideDistX  %f\n", o->cast.sideDistX);
			o->cast.mapX = o->cast.mapX + o->cast.stepX;
			// printf("1 mapX  %d\n", o->cast.mapX);
			side = 0;
		}
		else
		{
			o->cast.sideDistY = o->cast.sideDistY + o->cast.deltaDistY;
			// printf("2 sideDistY  %f\n", o->cast.sideDistY);
			o->cast.mapY = o->cast.mapY + o->cast.stepY;
			side = 1;
			// printf("2 mapY  %d SIDE %d\n", o->cast.mapY, side);
		}
		// printf("o->cast.mapX  %d o->cast.mapY  %d\n", o->cast.mapX, o->cast.mapY);
		if (o->s_str[o->cast.mapX][o->cast.mapY] == '1')
			hit = 1;
		// printf("HIT %d\n", hit);
		// sleep (5);
	}
	return (side);
}

/* После того, как DDA выполнено, мы должны рассчитать расстояние луча до стены, 
чтобы рассчитать, какой высоты стена должна быть нарисована 

* для этого мы расчитываем значение переменной wallDist(это расстояние от точки,
  где луч пересекает стену до точки на плоскости камеры, в которой линия образует прямой угол 
  (во избежание эффекта "fisheye")
  
  иллюстрация https://lodev.org/cgtutor/images/raycastdist.png
  и https://lodev.org/cgtutor/images/raycastperpwalldist2.png  
  
* В зависимости от того, 
  попадает ли луч на сторону X или сторону Y, 
  формула вычисляется с помощью sideDistX или sideDistY.*/

int	calc_wall_size(t_info *o, int side, int *line_height, int *start)
{
	int	end;

	if (side == 0)
		o->cast.wallDist = (o->cast.mapX - o->cast.posX + \
								(1 - o->cast.stepX) / 2) / o->cast.rayX; //perpWallDist = (sideDistX - deltaDistX); 
	
	else
		o->cast.wallDist = (o->cast.mapY - o->cast.posY + \
								(1 - o->cast.stepY) / 2) / o->cast.rayY; //perpWallDist = (sideDistY - deltaDistY);
	// printf("WallDist >> %f\n", o->cast.wallDist);
	//Рассчитываем высоту линии
	*line_height = (int)(WIN_H / o->cast.wallDist);
	// printf("LINE >> %d\n", *line_height);
	//вычисляем самый низкий и самый высокий пиксель для заполнения текущей полосы
	*start = -*line_height / 2 + o->R_height / 2;
	// printf("START >> %d\n", *start);
	if (*start < 0)
		*start = 0;
	end = *line_height / 2 + o->R_height / 2;
	if (end >= o->R_height)
		end = o->R_height - 1;
	// printf("END >> %d\n", end);
	// sleep(5);
	return (end);
}

static int	ft_choose_texture(t_info *o, int side)
{
	int tex;

	if (side == 1 && o->cast.rayY < 0)
		tex = 0;
	else if (side == 1 && o->cast.rayY >= 0)
		tex = 1;
	else if (side == 0 && o->cast.rayX < 0)
		tex = 2;
	else if (side == 0 && o->cast.rayX >= 0)
		tex = 3;
	else
		tex = -2;//error code
	return (tex);
}

double	ft_choose_pixel(t_info *o, int side, int line_height, double *texture_pos, int start)
{
	double	wallX;
	double	step;
	
	if (side == 0)
		wallX = o->cast.posY + o->cast.wallDist * o->cast.rayY;
	else
		wallX = o->cast.posX + o->cast.wallDist * o->cast.rayX;
	wallX = wallX - floor(wallX);
	// printf("WallX >> %f\n", wallX);
	// printf("INT_WallX >> %d  (double)TEX_W >> %f\n", (int)wallX, (double)TEX_W);
	o->textureX = (int)(wallX * (double)TEX_W);
	// printf("1 TextureX >> %d\n", o->textureX);
	if (side == 0 && o->cast.rayX > 0)
		o->textureX = TEX_W - o->textureX - 1;
	if (side == 1 && o->cast.rayY < 0)
		o->textureX = TEX_W - o->textureX - 1;
	// printf("2 TextureX >> %d\n", o->textureX);
	step = 1.0 * TEX_H / line_height;
	// printf("STEP >> %f\n", step );
	*texture_pos = (start - o->R_height / 2 + line_height / 2) * step;
	// printf("Texture_Pos >> %f\n", *texture_pos);
	o->cast.wy = start;
	// printf("Wall Y >>  %d\n", o->cast.wy);
	return (step);
}

static void	ft_pixels_screen_buf(t_info *o, int end, double *texture_pos, double step, int side)
{
	int color;
	int tex;

	// sleep(10);
	while (o->cast.wy < end)
	{
		o->textureY = (int)*texture_pos & (TEX_H - 1);
		*texture_pos += step;
		tex = ft_choose_texture(o, side);
		// printf("TEXXXXXX %d\n", tex);
		// printf("\n%d\n\n", o->textures[tex][TEX_H * o->textureY + o->textureX]);
		color = o->textures[tex][TEX_H * o->textureY + o->textureX];//SEGA
		// color = 0x7fff7f;
		if (side == 1)
			color = (color >> 1) & 0x7F7F7F;
		o->screen[o->cast.wy][o->cast.wx] = color;
		o->cast.wy++;
	}
}

void    wall_casting(t_info *o)
{
	int		side;
	int		line_height;
	double	texture_pos;
	int		start;
	int		end;
	double	step;

	o->cast.wx = 0;
	while(o->cast.wx < WIN_W)
	{
		get_the_angle(o);
		calc_step_n_sideDist(o);
		side = dd_analyzer(o);
		end = calc_wall_size(o, side, &line_height, &start);
		// printf("%d\n",line_height);
		step = ft_choose_pixel(o, side, line_height, &texture_pos, start);
		// printf("STEP >> %f\n", step );
		// sleep(5);
		ft_pixels_screen_buf(o, end, &texture_pos, step, side);
		o->cast.wx++;
	}
}

void	ft_render(t_info *o)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			o->img.data[y * WIN_W + x] = o->screen[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(o->mlx, o->wind, o->img.img, 0, 0);
}



  