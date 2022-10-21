#include "../include/cubd.h"

int	cheak_plaer(t_info	*o)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (o->s_str[++i])
	{
		j = -1;
		while (o->s_str[i][++j])
		{
			if (o->s_str[i][j] == 'N' || o->s_str[i][j] == 'W' || \
				o->s_str[i][j] == 'E' || o->s_str[i][j] == 'S')
			{
				flag++;
				o->y = i;
				o->x = j;
			}
		}
	}
	if (flag != 1)
		return (ft_error("bad argument..\n"));
	return (0);
}

void	closed_walls(t_info *o)
{
	int	i;
	int	j;

	o->y = -1;
	while (o->s_str[++(o->y)])
	{
		o->x = -1;
		while (o->s_str[o->y][++(o->x)])
			if (o->s_str[o->y][(o->x)] == '0' || o->s_str[o->y][(o->x)] == 'N' || o->s_str[o->y][(o->x)] == 'W' || \
				o->s_str[o->y][(o->x)] == 'E' || o->s_str[o->y][(o->x)] == 'S')
				chek_zero(o);
	}
	check_digit_arr(o->s_str);
	cheak_plaer(o);
}

void	construct_argv(char *filename, t_info *o)
{
	int		ch_len;
	char	*lane;
	int		fd;

	construct_str(filename, o);
	cheak_first_word(o);
	closed_walls(o);
}

int	parsing(int argc, char **argv, t_info *o)
{
	int		fd;
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (argc < 2)
		return (ft_error("no map specified.\n"));
	if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		return (ft_error("invalid map.\n"));
	construct_argv(argv[1], o);
	return (0);
}
