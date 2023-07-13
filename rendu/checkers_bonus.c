/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:19:19 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/22 20:47:57 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_check(t_map *map)
{
	map->height = 0;
	while (map->data[map->height] != NULL)
	{
		map->width = 0;
		if (map->height == 0)
			map->maxlenmap = ft_strlen(map->data[map->height]) - 1;
		map_len_lines_check(map);
		while (map->width < map->maxlenmap)
		{
			map_wall_check(map);
			map_car_check(map);
			++map->width;
		}
		++map->height;
	}
	if (map->data[map->height - 1][map->width] != '\0')
		check_errors(ERR_MAP_SIZE, map);
	map_integrity_check(map);
}

void	map_wall_check(t_map *map)
{
	if (map->height == 0 || map->height == map->maxline - 1)
		if (map->data[map->height][map->width] != '1')
			check_errors(ERR_MAP_WALLS, map);
	if (!map->width || map->width == map->maxlenmap - 1)
		if (map->data[map->height][map->width] != '1')
			check_errors(ERR_MAP_WALLS, map);
}

void	map_car_check(t_map *map)
{
	if (map->width >= 0 && map->width <= map->maxlenmap - 1)
		if ((map->data[map->height][map->width] != '0') \
		&& (map->data[map->height][map->width] != '1') \
		&& (map->data[map->height][map->width] != 'C') \
		&& (map->data[map->height][map->width] != 'E') \
		&& (map->data[map->height][map->width] != 'P') \
		&& (map->data[map->height][map->width] != 'F'))
			check_errors(ERR_MAP_DATA, map);
	if (map->data[map->height][map->width] == 'C')
		++map->nbcollectible;
	if (map->data[map->height][map->width] == 'E')
		++map->nbexit;
	if (map->data[map->height][map->width] == 'P')
		++map->nbplayer;
}

void	map_len_lines_check(t_map *map)
{
	if (map->height < map->maxline - 1)
	{
		if (map->maxlenmap != ft_strlen(map->data[map->height]) - 1)
			check_errors(ERR_MAP_SIZE, map);
	}
	else if (map->maxlenmap != ft_strlen(map->data[map->height]))
		check_errors(ERR_MAP_SIZE, map);
}

void	map_integrity_check(t_map *map)
{
	if (map->nbcollectible == 0)
		check_errors(ERR_MAP_COMPOSITION, map);
	if (map->nbexit == 0)
		check_errors(ERR_MAP_COMPOSITION, map);
	if (map->nbplayer != 1)
		check_errors(ERR_MAP_COMPOSITION, map);
}
