/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:09:22 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/22 20:49:21 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	launch_map(t_map *map, t_data *data)
{
	t_var	*var;

	var = ft_calloc(1, sizeof(t_var));
	if (var == NULL)
	{
		free(var);
		check_errors(ERR_MALLOC, NULL);
	}
	var->map = map;
	var->data = data;
	init_data(map, data);
	print_map(var);
	data->x = data->player_x;
	data->y = data->player_y;
	mlx_hook(data->win, X_EVENT_KEY_PRESS, 1L << 0, key_press, var);
	mlx_hook(data->win, EXIT_CROSS, 1L << 17, close_win, var);
	mlx_loop_hook(data->mlx, animated_fire, var);
	mlx_loop(data->mlx);
}

void	init_data(t_map *map, t_data *data)
{
	data->pxwidth = map->maxlenmap * SIZE_BLOCK;
	data->pxheight = map->height * SIZE_BLOCK;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, data->pxwidth, data->pxheight, \
	"So Long");
	if (data->win == NULL)
	{
		free(data->win);
		check_errors(ERR_MALLOC, NULL);
	}
	data->img = mlx_new_image(data->mlx, data->pxwidth, data->pxheight);
	if (data->img == NULL)
	{
		free(data->img);
		check_errors(ERR_MALLOC, NULL);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	if (data->addr == NULL)
	{
		free(data->addr);
		check_errors(ERR_MALLOC, NULL);
	}
}

void	print_map(t_var *var)
{
	var->data->y = 0;
	while (var->data->y < var->map->maxline)
	{
		var->data->x = 0;
		while (var->data->x < var->map->maxlenmap)
		{
			if (var->map->data[var->data->y][var->data->x] == '0')
				put_xpm("img/ground.xpm", var->data);
			else if (var->map->data[var->data->y][var->data->x] == '1')
				put_xpm("img/wall.xpm", var->data);
			else if (var->map->data[var->data->y][var->data->x] == 'C')
				put_xpm("img/collectible.xpm", var->data);
			else if (var->map->data[var->data->y][var->data->x] == 'E')
				put_xpm("img/exit.xpm", var->data);
			else if (var->map->data[var->data->y][var->data->x] == 'P')
				set_player_pos(var);
			else if (var->map->data[var->data->y][var->data->x] == 'F')
				animated_fire(var);
			++var->data->x;
		}
		++var->data->y;
	}
}

void	put_xpm(char *file, t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, file, \
	&data->px_w_size, &data->px_h_size);
	if (data->img == NULL)
		check_errors(ERR_OPEN_FILE, NULL);
	if ((SIZE_BLOCK != data->px_w_size || SIZE_BLOCK != data->px_h_size))
		check_errors(ERR_SIZE_BLOCK, NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, \
	data->x * data->px_w_size, data->y * data->px_h_size);
}

int	key_press(int keycode, t_var *var)
{
	if ((keycode == KEY_A) || (keycode == KEY_S) \
	|| (keycode == KEY_D) || (keycode == KEY_W))
	{
		if (move_player(keycode, var))
			print_moves(var->data);
	}
	if (keycode == KEY_ESC)
	{
		printf("Good BYE !\n");
		mlx_destroy_window(var->data->mlx, var->data->win);
		mlx_destroy_image(var->data->mlx, var->data->img);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
