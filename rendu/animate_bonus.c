/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:00:45 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/22 20:47:25 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_death(t_map *map, t_data *data)
{
	(void)map;
	printf("GAME OVER at %d moves !\n", data->nb_moves);
	data->endgame = 1;
	mlx_string_put(data->mlx, data->win, \
	data->x * data->px_w_size - 30, data->y * data->px_h_size, \
	0xFF0000, "~~ GAME OVER ! ~~");
}

void	print_moves(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "img/ground.xpm", \
	&data->px_w_size, &data->px_h_size);
	if (data->img == NULL)
		check_errors(ERR_OPEN_FILE, NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, \
	-data->px_h_size / 2);
	mlx_string_put(data->mlx, data->win, data->px_w_size / 8, \
	data->px_h_size / 3, 0x0000FF, ft_itoa(data->nb_moves));
}

void	fire_state(t_data *data)
{
	if (data->fire_state == 0)
	{
		put_xpm_fire("img/ground.xpm", data);
		put_xpm_fire("img/fire1.xpm", data);
	}
	else if (data->fire_state == 1)
	{
		put_xpm_fire("img/ground.xpm", data);
		put_xpm_fire("img/fire2.xpm", data);
	}
	else if (data->fire_state == 2)
	{
		put_xpm_fire("img/ground.xpm", data);
		put_xpm_fire("img/fire3.xpm", data);
	}
	else if (data->fire_state == 3)
	{
		put_xpm_fire("img/ground.xpm", data);
		put_xpm_fire("img/fire4.xpm", data);
	}
	else if (data->fire_state == 4)
	{
		put_xpm_fire("img/ground.xpm", data);
		put_xpm_fire("img/fire5.xpm", data);
	}
}

int	animated_fire(t_var *var)
{
	usleep(50000);
	var->data->j_fire = 0;
	while (var->data->j_fire < var->map->maxline)
	{
		var->data->i_fire = 0;
		while (var->data->i_fire < var->map->maxlenmap)
		{
			if (var->map->data[var->data->j_fire][var->data->i_fire] == 'F')
				fire_state(var->data);
			++var->data->i_fire;
		}
		++var->data->j_fire;
	}
	if (++var->data->fire_state > 4)
		var->data->fire_state = 0;
	return (0);
}

void	put_xpm_fire(char *file, t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, file, \
	&data->px_w_size, &data->px_h_size);
	if (data->img == NULL)
		check_errors(ERR_OPEN_FILE, NULL);
	if ((SIZE_BLOCK != data->px_w_size || SIZE_BLOCK != data->px_h_size))
		check_errors(ERR_SIZE_BLOCK, NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, \
	data->i_fire * data->px_w_size, data->j_fire * data->px_h_size);
}
