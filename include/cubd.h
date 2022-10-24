/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubd.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:41:01 by rjada             #+#    #+#             */
/*   Updated: 2022/10/24 14:48:02 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBD_H
# define CUBD_H

# include "../libft/libft.h"
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include   <math.h>
# include	"../mlx/mlx.h"

# define TEX_W 64
# define TEX_H 64
# define WIN_W 640
# define WIN_H 480

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# define REDCROSS 17
# define PRESS 2
# define RELEASE 3
# define BUFFER_SIZE 1

typedef struct s_key
{
	int		kopen;
	int		kesc;
	int		kup;
	int		kdown;
	int		kleft;
	int		kright;
	int		karr_left;
	int		karr_right;
}			t_key;

typedef struct s_img
{
	void	*img;
	int		len;
	int		bpp;
	int		endian;
	int		img_w;
	int		img_h;
	int		*data;
}			t_img;

typedef struct s_cast
{
	double	posX;
	double	posY;
	double	planeX;
	double	planeY;
	double  dirX;
	double  dirY;
	double  camX;
	double  rayX;//направление луча
	double  rayY;//вычисляется как сумма направления взгляда игрока и плоскости камеры
	int     wx;
	int     wy;
	int     mapX;//текущая клетка карты, 
	int     mapY;//в которой находится луч
	double  sideDistX;//изначально это расстояние, которое луч должен пройти от начальной позиции до первой стороны x и первой стороны y. 
	double  sideDistY;//Позже в коде они будут увеличиваться по мере выполнения шагов.
	double  deltaDistX;//расстояние, которое должен пройти луч, 
	double  deltaDistY;//чтобы пройти от 1 стороны x(y) до следующей стороны x(y)
	double  wallDist;//будет использоваться для вычисления длины луча
	int     stepX;//шаг
	int     stepY;
}t_cast;

typedef struct s_info
{
	char	**argv;
	char	**s_str;

	int		x;
	int		y;
	int		fd;
	void	*wind;
	void	*mlx;
	int		R_width;
	int		R_height;
	void	*NO;
	void	*SO;
	void	*WE;
	void	*EA;
	int		F;
	int		C;
	int		screen[WIN_H][WIN_W];
	int		**textures;
	int		textureX;
	int		textureY;
	t_cast	cast;
	t_img	img;
	t_key	k;
}t_info;

// init
void	init_info(t_info *new);

static void ft_import_imgxpm(t_info *o, int *texture, char *path, t_img *img);

void	ft_import_textures(t_info *o);
int		parsing(int argc, char **argv, t_info *info);
void	chek_zero(t_info *o);
int		check_digit_arr(char **argv);
int		association_str(char **s_str);
void	construct_str(char *filename, t_info *o);

// utilus
int		ft_error(char *str);
int		check_digit_str(char *str);
void	ft_free_darr(char **argv);
void	ft_print_darr(char **argv, int fd);
char	**ft_strdup_two(char **s1);

char	*get_next_line_mod(int fd);

void	free_info(t_info **info);
int		association_str(char **s_str);

void	cheak_first_word(t_info *o);

int		word_add_r(t_info *o, char **s_str);
int		word_add_no(t_info *o, char **s_str);
int		word_add_ea(t_info *o, char **s_str);
int		word_add_so(t_info *o, char **s_str);
int		word_add_we(t_info *o, char **s_str);

void	ft_import_textures(t_info *o);

//rays.c
// int	alloc_texture_arr(t_info *o);

void	init_data(t_info *o);
void	get_the_angle(t_info *o);
void	calc_step_n_sideDist(t_info *o);
int		dd_analyzer(t_info *o);
int		calc_wall_size(t_info *o, int side, int *line_height, int *start);
double	ft_choose_pixel(t_info *o, int side, int line_height, double *texture_pos, int start);
void	wall_casting(t_info *o);
void	ft_render(t_info *o);

//key.c
int		ft_key_press(int key, t_info *o);
int		ft_key_release(int key, t_info *o);
void	ft_player_rotate_r(t_info *o);
void	ft_player_rotate_l(t_info *o);
void	ft_key_action(t_info *o);

//action.c
void	ft_player_forward(t_info *o);
void	ft_player_backward(t_info *o);
void	ft_player_left(t_info *o);
void	ft_player_right(t_info *o);

#endif
