/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:21:43 by hlely             #+#    #+#             */
/*   Updated: 2018/05/18 14:13:54 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		delete_tetri(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->ty)
	{
		free(map->tetri[i]);
		map->tetri[i] = NULL;
		i++;
	}
	map->tx = -1;
	map->ty = -1;
	map->ntx = 0;
	map->nty = 0;
}

void		delete_possibilities(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		if (tmp->content)
			free(tmp->content);
		if (tmp)
			free(tmp);
	}
	*list = NULL;
}