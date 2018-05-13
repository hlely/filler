/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:52:30 by hlely             #+#    #+#             */
/*   Updated: 2018/05/13 11:07:13 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map	init_map(void)
{
	t_map	map;

	map.xmax = -1;
	map.ymax = -1;
	map.map = NULL;
	map.weight = NULL;
	map.tetri = NULL;
	map.c = 0;
	map.len = -1;
	return (map);
}

t_map	get_mapdim(t_map map, char *line)
{
	int		i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	map.ymax = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	map.xmax = ft_atoi(line + i);
	map.map = (char**)ft_memalloc(sizeof(char*) * (map.ymax + 1));
	ft_dprintf(2, "xmax[%d] ymax[%d]\n", map.xmax, map.ymax);
	return (map);
}

t_map	update_map(t_map map)
{
	int		i;
	char	*line;

	i = 0;
	while (i < map.ymax)
	{
		get_next_line(STDIN_FILENO, &line);
		ft_strdel(&map.map[i]);
		if (line)
			map.map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	return (map);
}

int			get_map(t_map map)
{
	int		ret;
	char	*line;

	ft_dprintf(2, "Starting\n");
	ret = get_next_line(STDIN_FILENO, &line);
	map.c = (*(line + 10) == '1') ? 'O' : 'X';
	ft_strdel(&line);
	while (1)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		map = map.map == NULL ? get_mapdim(map, line) : map;
		ft_strdel(&line);
		get_next_line(STDIN_FILENO, &line);
		ft_strdel(&line);
		map = update_map(map);
		/* show_map(map); */
		map = fill_piece(map);
		if (put_piece(&map) == 0)
			return (0);
	}
	return (1);
}
