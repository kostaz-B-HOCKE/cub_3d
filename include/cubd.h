/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <rjada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:41:01 by rjada             #+#    #+#             */
/*   Updated: 2022/05/30 19:18:04 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBD_H
# define CUBD_H

# include "../libft/libft.h"
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	"minilibx_opengl_20191021/mlx.h"

typedef struct s_info
{
    char **argv;
    char **check;
    int height;
    int width;
    void *wind;
    void *mlx;
    void    *NO;
    void    *SO;
    void    *WE;
    int     F;
    int     C;
    int     x;
    int     y;
}       t_info;

//init
void    init_info(t_info *new);

//parsing.c
int parsing(int argc, char **argv, t_info *info);

//utilus
int   ft_error(char *str);
int check_digit_str(char *str);
void    ft_free_darr(char **argv);
void    ft_print_darr(char **argv, int fd);
char **ft_strdup_two(char **s1);

void    free_info(t_info **info);
char *association_str(char **s_str);

char	*get_next_line_mod(int fd);

int wall_inspection(t_info *info);
int pars_word(char **s_str, t_info *info);

int word_add_NO(t_info *info, char **s_str);
int word_add_SO(t_info *tmp);
int word_add_WE(t_info *tmp);
int word_add_EA(t_info *tmp);

int offset_1(t_info *o);
int offset_2(t_info *o);
int offset_3(t_info *o);
int offset_4(t_info *o);
int offset_5(t_info *o);
int offset_6(t_info *o);
int offset_7(t_info *o);
int offset_8(t_info *o);
int offset_9(t_info *o);

#endif
