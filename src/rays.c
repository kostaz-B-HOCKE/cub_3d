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

void init_data(t_info *o)
{
	t_cast cast;

	cast.posX = 15,5;//(double)o->x; Позиция игрока на карте + 0,5 
	cast.posY = 11,5;//(double)o->y; Позиция игрока на карте + 0,5
	cast.planeX = 0;
	cast.planeY = 0.66; //the 2d raycaster version of camera plane
	cast.dirX = -1;
	cast.dirY = 0; //initial direction vector
	cast.wx = 0;
	o->cast = cast;
}

void    img_rendering(t_info *o)//эта ф-ция вызывается в цикле в get_direction()
{   
	//calculate ray position and direction
	o->cast.camX = 2 * o->cast.wx / (double)o->R_width - 1; //x-coordinate in camera space (переводим из 0..640 в -1..1)
	o->cast.rayX = o->cast.dirX + o->cast.planeX * o->cast.camX;//(-1 + 0*(-1..1))
	o->cast.rayY = o->cast.dirY + o->cast.planeY * o->cast.camX;//0+0.66*(-1..1)
	o->cast.mapX = (int)o->cast.posX;
	o->cast.mapY = (int)o->cast.posY;
	o->cast.deltaDistX = fabs(1 / o->cast.rayX);
	o->cast.deltaDistY = fabs(1 / o->cast.rayY);
}

void	calc_step_n_sideDist(t_info *o)// вычисляем шаг и начальное значение sideDist
{
	if (o->cast.rayX < 0)
	{
		o->cast.stepX = -1;
		o->cast.sideDistX = (o->cast.posX - o->cast.mapX) * o->cast.deltaDistX;
	}
	else
	{
		o->cast.stepX = 1;
		o->cast.sideDistX = (o->cast.mapX + 1.0 - o->cast.posX) * o->cast.deltaDistX;
	}
	if  (o->cast.rayY < 0)
	{
		o->cast.stepY = -1;
		o->cast.sideDistY = (o->cast.posY - o->cast.mapY) * o->cast.deltaDistY;
	}
	else
	{
		o->cast.stepY = 1;
		o->cast.sideDistY = (o->cast.mapY + 1.0 - o->cast.posY) * o->cast.deltaDistY;
	}
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
		if (o->cast.sideDistX < o->cast.sideDistY)
		{
			o->cast.sideDistX = o->cast.sideDistX + o->cast.deltaDistX;
			o->cast.mapX = o->cast.mapX + o->cast.stepX;
			side = 0;
		}
		else
		{
			o->cast.sideDistY = o->cast.sideDistY + o->cast.deltaDistY;
			o->cast.mapY = o->cast.mapY + o->cast.stepY;
			side = 1;
		}
		if (o->s_str[o->cast.mapX][o->cast.mapY] == '1')
			hit = 1;
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
	//Рассчитываем высоту линии
	*line_height = (int)(o->R_height / o->cast.wallDist);
	//вычисляем самый низкий и самый высокий пиксель для заполнения текущей полосы
	*start = -*line_height / 2 + o->R_height / 2;
	if (*start < 0)
		*start = 0;
	end = *line_height / 2 + o->R_height / 2;
	if (end >= o->R_height)
		end = o->R_height - 1;
	return (end);
}

double	ft_choose_pixel(t_info *o, int side, int line_height, double *texture_pos, int start)
{
	double	wallX;
	double	step;
	
	// ft_choose_texture();
	if (side == 0)
		wallX = o->cast.posY + o->cast.wallDist * o->cast.rayY;
	else
		wallX = o->cast.posX + o->cast.wallDist * o->cast.rayX;
	wallX = wallX - floor(wallX);
	o->textureX = (int)wallX * (double)TEX_W;
	if (side == 0 && o->cast.rayX > 0)
		o->textureX = TEX_W - o->textureX - 1;
	if (side == 1 && o->cast.rayY < 0)
		o->textureX = TEX_W - o->textureX - 1;
	step = 1.0 * TEX_H / line_height;
	*texture_pos = (start - o->R_height / 2 + line_height / 2) * step;
	o->cast.wy = start;

	return (step);
}

// void	ft_pixels_screen_buf(t_info *o, int end, double *texture_pos, double step, int side)
// {
// 	int color;

// 	while (o->cast.wy < end)
// 	{
// 		o->textureY = (int)*texture_pos & (TEX_H - 1);
// 		*texture_pos += step;
// 		color = 7340032;
// 		if (side == 1)
// 			color = (color >> 1) & 0x7F7F7F;
// 		// glb->buf_img[wall->y][wall->x] = wall->color;
// 		o->cast.wy++;
// 	}
// }

void    get_direction(t_info *o)
{
	int		side;
	int		line_height;
	double	texture_pos;
	int		start;
	int		end;
	double	step;

	while(o->cast.wx < o->R_width)
	{
		img_rendering(o);
		calc_step_n_sideDist(o);
		side = dd_analyzer(o);
		end = calc_wall_size(o, side, &line_height, &start);
		step = ft_choose_pixel(o, side, line_height, &texture_pos, start);
		ft_pixels_screen_buf(o, end, &texture_pos, step, side);
	}
}





  