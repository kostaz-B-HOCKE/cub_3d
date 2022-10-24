/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_add_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:23:51 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/24 16:49:02 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

int	word_add_r(t_info *o, char **s_str)
{
	int	i;

	i = 0;
	while (s_str[i++])
		;
	if (i != 4)
		return (ft_error("bad argument.\n"));
	if (check_digit_str(s_str[1]) || check_digit_str(s_str[2]))
		return (ft_error("bad argument.\n"));
	o->r_height = ft_atoi(s_str[1]);
	o->r_width = ft_atoi(s_str[2]);
	return (0);
}

int	word_add_no(t_info *o, char **s_str)
{
	int	x;
	int	y;

	y = -1;
	while (s_str[++y])
		;
	if (y != 2)
		return (ft_error("bad argument.\n"));
	return (0);
}

int	word_add_so(t_info *o, char **s_str)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (s_str[++i])
		;
	if (i != 2)
		return (ft_error("bad argument.\n"));
	return (0);
}

int	word_add_we(t_info *o, char **s_str)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (s_str[++i])
		;
	if (i != 2)
		return (ft_error("bad argument.\n"));
	return (0);
}

int	word_add_ea(t_info *o, char **s_str)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (s_str[++i])
		;
	if (i != 2)
		return (ft_error("bad argument.\n"));
	return (0);
}
