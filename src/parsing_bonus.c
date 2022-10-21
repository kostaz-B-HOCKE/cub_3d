#include "../include/cubd.h"

int	check_digit_arr(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != 'S' && argv[i][j] != 'E' && argv[i][j] != 'W' &&
				argv[i][j] != 'N' && argv[i][j] != ' ')
			{
				printf("c:%c\n", argv[i][j]);
				return (ft_error("bad argument.\n"));
			}
		}
	}
	return (0);
}

int	association_str(char **s_str)
{
	int	color;

	color = ft_atoi(s_str[0]);
	color = color + ft_atoi(s_str[1]) * 255;
	color = color + ft_atoi(s_str[2]) * 255 * 255;
	return (color);
}

void	construct_str(char *filename, t_info *o)
{
	char	*lane;
	int		i;
	int		fd;
	char	**s_str;
	char	tmp;

	i = 0;
	fd = open(filename, O_RDONLY);
	while((lane = get_next_line(fd)))
	{
		if (ft_strlen(lane))
			i++;
		free(lane);
	}
	o->s_str = (char **)malloc(sizeof(char *) * (i + 1));
	if (!o->s_str)
		ft_error("malloc error\n");
	i = -1;
	fd = open(filename, O_RDONLY);
	while((lane = get_next_line(fd)))
		if (ft_strlen(lane))
			o->s_str[++i] = lane;
	o->s_str[++i] = 0;
}

int	start_sim(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	chek_zero(t_info *o)
{
	if (!(o->s_str[o->y][(o->x + 1)] && start_sim(o->s_str[o->y][(o->x + 1)])) ||
	!(o->s_str[o->y][(o->x - 1)] && start_sim(o->s_str[o->y][(o->x - 1)])) || \
		!(o->s_str[o->y + 1][o->x] && start_sim(o->s_str[o->y + 1][o->x])) ||
		!(o->s_str[o->y - 1][(o->x)] && start_sim(o->s_str[o->y - 1][(o->x)])))
	{
		ft_error("bad mapw");
	}
}