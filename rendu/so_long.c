/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:16:15 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/22 20:28:00 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	*data;

	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
	{
		free(map);
		check_errors(ERR_MALLOC, NULL);
	}
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
	{
		free(data);
		check_errors(ERR_MALLOC, NULL);
	}
	if (argc != 2)
		check_errors(ERR_ARGS, NULL);
	check_file_ext(argv[1]);
	read_map_data(argv[1], map);
	map_check(map);
	launch_map(map, data);
	free_all_ptr(map, data);
	return (0);
}

int	close_win(t_var *var)
{
	printf("Good BYE !\n");
	mlx_destroy_window(var->data->mlx, var->data->win);
	mlx_destroy_image(var->data->mlx, var->data->img);
	exit(EXIT_SUCCESS);
}

int	end_game(t_map *map, t_data *data)
{
	if (map->nbcollectible == 0)
	{
		printf("Good Game YOU WIN with %d moves !\n", data->nb_moves);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	free_all_ptr(t_map *map, t_data *data)
{
	ft_free_tab(map->data);
	ft_free_ptr(data->mlx);
	ft_free_ptr(data->win);
	ft_free_ptr(data->img);
	ft_free_ptr(data->addr);
	free(map);
	free(data);
}

void	set_player_pos(t_data *data)
{
	data->player_x = data->x;
	data->player_y = data->y;
	put_xpm("img/ground.xpm", data);
	put_xpm("img/down_s.xpm", data);
}
