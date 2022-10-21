/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:24:12 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/21 19:24:13 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

int	check_digit_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (ft_error("bad argument.\n"));
	}
	return (0);
}

int	ft_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	exit(1);
	return (1);
}

void	ft_print_darr(char **argv, int fd)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			ft_putstr_fd(argv[i++], fd);
			ft_putstr_fd("\n", fd);
		}
	}
	else
		ft_putstr_fd("no ARGV\n", fd);
}

char	**ft_strdup_two(char **s1)
{
	int		len;
	char	**s2;

	if (!s1 || !*s1)
		return (NULL);
	len = 0;
	while ((*s1)[len])
		len++;
	s2 = (char **)malloc(sizeof(char *) * (len + 1));
	if (!s2)
		return (NULL);
	len = -1;
	while (s1[++len])
		s2[len] = ft_strdup(s1[len]);
	s2[len] = 0;
	return (s2);
}
