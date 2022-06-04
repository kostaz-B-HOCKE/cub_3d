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
    int height;
    int width;
    void    *NO;
    void    *SO;
    void    *WE;
    int     *F;
    int     *S;
}       t_info;

//init
void    init_info(t_info **new);

//parsing.c
int parsing(int argc, char **argv, t_info *info);

//utilus
int   ft_error(char *str);
int check_digit_str(char *str);
void    ft_free_darr(char **argv);
void    ft_print_darr(char **argv, int fd);


void    free_info(t_info **info);

char	*get_next_line_mod(int fd);

int pars_word(char **s_str, t_info *info);


#endif
