/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_part_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:23:33 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/21 19:23:35 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

int	word_add_f(t_info *o, char **s_str)
{
	int		i;
	char	**str_split;

	i = 0;
	while (s_str[i++])
		;
	if (i != 3)
		return (ft_error("bad argument.\n"));
	str_split = ft_split(s_str[1], ',');
	if (check_digit_str(str_split[0]) || check_digit_str(str_split[1]) || \
		check_digit_str(str_split[2]))
		return (ft_error("bad argument.\n"));
	o->F = association_str(str_split);
	ft_free_darr(str_split);
	return (0);
}

int	word_add_c(t_info *o, char **s_str)
{
	int		i;
	char	**str_split;

	i = 0;
	while (s_str[i++])
		;
	if (i != 3)
		return (ft_error("bad argument.\n"));
	str_split = ft_split(s_str[1], ',');
	if (check_digit_str(str_split[0]) || check_digit_str(str_split[1]) || \
		check_digit_str(str_split[2]))
		return (ft_error("bad argument.\n"));
	o->C = association_str(str_split);
	ft_free_darr(str_split);
	return (0);
}

int	pars_wordd(t_info *o, char **s_str)
{
	if (!ft_strcmp(s_str[0], "R"))
		return (word_add_r(o, s_str));
	if (!ft_strcmp(s_str[0], "NO"))
		return (word_add_no(o, s_str));
	if (!ft_strcmp(s_str[0], "SO"))
		return (word_add_so(o, s_str));
	if (!ft_strcmp(s_str[0], "WE"))
		return (word_add_we(o, s_str));
	if (!ft_strcmp(s_str[0], "EA"))
		return (word_add_ea(o, s_str));
	if (!ft_strcmp(s_str[0], "F"))
		return (word_add_f(o, s_str));
	if (!ft_strcmp(s_str[0], "C"))
		return (word_add_c(o, s_str));
	return (1);
}

void	cutting_first_argv(t_info *o)
{
	int		i;
	char	**new_s_str;

	i = -1;
	while (o->s_str[++i])
		;
	new_s_str = (char **)malloc(sizeof(char *) * (i));
	if (!new_s_str)
		ft_error("malloc\n");
	i = 0;
	while (o->s_str[i] && o->s_str[i + 1])
	{
		new_s_str[i] = o->s_str[i + 1];
		i++;
	}
	new_s_str[i] = 0;
	if (o->s_str)
		free(o->s_str);
	o->s_str = new_s_str;
}

void	cheak_first_word(t_info *o)
{
	char	**s_split;

	while (1)
	{
		s_split = ft_split(o->s_str[0], ' ');
		if (pars_wordd(o, s_split))
			break ;
		else
			cutting_first_argv(o);
		ft_free_darr(s_split);
	}
}
