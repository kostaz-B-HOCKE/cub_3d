/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <eabradol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:31:05 by eabradol          #+#    #+#             */
/*   Updated: 2022/10/24 14:31:46 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubd.h"

static char	*ftt_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	n;
	char	*str;
	size_t	len;

	i = -1;
	n = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++n])
		str[i + n] = s2[n];
	str[i + n] = '\0';
	free(s1);
	return (str);
}

static int	kot(int fd, char *buf, char **thc)
{
	int	b;

	b = read(fd, buf, BUFFER_SIZE);
	while (b > 0)
	{
		buf[b] = '\0';
		if (!*thc)
			*thc = ft_substr(buf, 0, b);
		else
			*thc = ftt_strjoin(*thc, buf);
		if (ft_strchr(buf, '\n'))
			break ;
		b = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (b);
}

static char	*kot2(char **thc, int b)
{
	int		j;
	char	*ret;
	char	*tmp;

	if (!*thc)
		return (0);
	if (b == 0 && *thc[0] == '\0')
	{
		free(*thc);
		*thc = 0;
		return (NULL);
	}
	if (!ft_strchr(*thc, '\n'))
	{
		ret = ft_substr(*thc, 0, ft_strlen(*thc));
		free(*thc);
		*thc = 0;
		return (ret);
	}
	j = ft_strlen(ft_strchr(*thc, '\n'));
	ret = ft_substr(*thc, 0, ft_strlen(*thc) - j);
	tmp = *thc;
	*thc = ft_substr(ft_strchr(*thc, '\n'), 1, j);
	free(tmp);
	return (ret);
}

char	*get_next_line_mod(int fd)
{
	static char	*thc;
	char		*buf;
	int			b;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (BUFFER_SIZE <= 0 || fd == -1 || !buf || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (NULL);
	}
	b = kot(fd, buf, &thc);
	return (kot2(&thc, b));
}
