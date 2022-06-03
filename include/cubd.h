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

}       t_info;

//init
void    init_info(t_info **new);

//parsing.c
int parsing(int argc, char **argv, t_info *info);

//utilus
int   ft_error(char *str);

void    free_info(t_info **info);

char	*get_next_line_mod(int fd);mak


#endif
