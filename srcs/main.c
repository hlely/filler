/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:43:22 by hlely             #+#    #+#             */
/*   Updated: 2018/05/13 11:02:06 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	show_map(t_map map)
{
	int		i;
	int		j;

	j = 0;
	ft_printf("xmax :[%d]\nymax :[%d]\n", map.xmax, map.ymax);
	while (j < map.ymax)
	{
		i = 0;
		ft_dprintf(2, "[%2d] %s\n", j, map.map[j]);
		j++;
	}
}

void	show_tetri(t_map map)
{
	int		i;
	int		j;

	j = 0;
	while (j < map.ty)
	{
		i = 0;
		ft_dprintf(2, "%s\n", map.tetri[j]);
		j++;
	}
}

int		main(void)
{
	int		i;
	t_map	map;

	i = 0;
	map = init_map();
	if (!get_map(map))
		return (0);
	show_map(map);
	free(map.map);
	return (0);
}
