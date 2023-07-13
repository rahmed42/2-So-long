/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:19:18 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/22 20:42:05 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keycode, t_var *var)
{
	if (keycode == KEY_W)
	{
		if (move_up_w(var->map, var->data))
			return (1);
	}
	else if (keycode == KEY_S)
	{
		if (move_down_s(var->map, var->data))
			return (1);
	}
	else if (keycode == KEY_A)
	{
		if (move_left_a(var->map, var->data))
			return (1);
	}
	else if (keycode == KEY_D)
	{
		if (move_right_d(var->map, var->data))
			return (1);
	}
	return (0);
}

int	move_up_w(t_map *map, t_data *data)
{
	if ((map->data[data->y - 1][data->x] == '0') \
	|| (map->data[data->y - 1][data->x] == 'C') \
	|| (map->data[data->y - 1][data->x] == 'E'))
	{
		++(data->nb_moves);
		if (map->data[data->y][data->x] != 'E')
		{
			map->data[data->y][data->x] = '0';
			put_xpm("img/ground.xpm", data);
		}
		else
			put_xpm("img/exit.xpm", data);
		--(data->y);
		if (map->data[data->y][data->x] == 'C')
			--(map->nbcollectible);
		if (map->data[data->y][data->x] == 'E')
			end_game(map, data);
		put_xpm("img/up_w.xpm", data);
		return (1);
	}
	return (0);
}

int	move_down_s(t_map *map, t_data *data)
{
	if ((map->data[data->y + 1][data->x] == '0') \
	|| (map->data[data->y + 1][data->x] == 'C') \
	|| (map->data[data->y + 1][data->x] == 'E'))
	{
		++(data->nb_moves);
		if (map->data[data->y][data->x] != 'E')
		{
			map->data[data->y][data->x] = '0';
			put_xpm("img/ground.xpm", data);
		}
		else
			put_xpm("img/exit.xpm", data);
		++(data->y);
		if (map->data[data->y][data->x] == 'C')
			--(map->nbcollectible);
		if (map->data[data->y][data->x] == 'E')
			end_game(map, data);
		put_xpm("img/down_s.xpm", data);
		return (1);
	}
	return (0);
}

int	move_left_a(t_map *map, t_data *data)
{
	if ((map->data[data->y][data->x - 1] == '0') \
	|| (map->data[data->y][data->x - 1] == 'C') \
	|| (map->data[data->y][data->x - 1] == 'E'))
	{
		++(data->nb_moves);
		if (map->data[data->y][data->x] != 'E')
		{
			map->data[data->y][data->x] = '0';
			put_xpm("img/ground.xpm", data);
		}
		else
			put_xpm("img/exit.xpm", data);
		--(data->x);
		if (map->data[data->y][data->x] == 'C')
			--(map->nbcollectible);
		if (map->data[data->y][data->x] == 'E')
			end_game(map, data);
		put_xpm("img/left_a.xpm", data);
		return (1);
	}
	return (0);
}

int	move_right_d(t_map *map, t_data *data)
{
	if ((map->data[data->y][data->x + 1] == '0') \
	|| (map->data[data->y][data->x + 1] == 'C') \
	|| (map->data[data->y][data->x + 1] == 'E'))
	{
		++(data->nb_moves);
		if (map->data[data->y][data->x] != 'E')
		{
			map->data[data->y][data->x] = '0';
			put_xpm("img/ground.xpm", data);
		}
		else
			put_xpm("img/exit.xpm", data);
		++(data->x);
		if (map->data[data->y][data->x] == 'C')
			--(map->nbcollectible);
		else if (map->data[data->y][data->x] == 'E')
			end_game(map, data);
		put_xpm("img/right_d.xpm", data);
		return (1);
	}
	return (0);
}
