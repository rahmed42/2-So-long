/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:16:48 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/22 20:29:11 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define SIZE_BLOCK 50

# define X_EVENT_KEY_PRESS 2

# define EXIT_CROSS 17
# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

enum		e_errors
{
	ERR_ARGS,
	ERR_FILENAME_FORMAT,
	ERR_OPEN_FILE,
	ERR_MALLOC,
	ERR_MAP_WALLS,
	ERR_MAP_DATA,
	ERR_MAP_SIZE,
	ERR_MAP_COMPOSITION,
	ERR_SIZE_BLOCK
};

typedef struct s_map
{
	char	**data;
	size_t	width;
	size_t	height;
	size_t	maxlenmap;
	size_t	maxline;
	size_t	nbcollectible;
	size_t	nbexit;
	size_t	nbplayer;
}	t_map;

typedef struct s_data
{
	size_t	x;
	size_t	y;
	size_t	player_x;
	size_t	player_y;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		nb_moves;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		pxwidth;
	int		pxheight;
	int		px_w_size;
	int		px_h_size;
	int		endgame;
	int		fire_state;
	size_t	i_fire;
	size_t	j_fire;
}	t_data;

typedef struct s_var
{
	t_map	*map;
	t_data	*data;
}	t_var;

int		close_win(t_var *var);
void	free_all_ptr(t_map *map, t_data *data);
void	map_check(t_map *map);
void	map_wall_check(t_map *map);
void	map_car_check(t_map *map);
void	map_len_lines_check(t_map *map);
void	map_integrity_check(t_map *map);
void	check_errors(size_t err, t_map *map);
void	read_map_lines(char *filename, t_map *map);
void	check_file_ext(char *filename);
void	read_map_data(char *filename, t_map *map);
void	launch_map(t_map *map, t_data *data);
void	init_data(t_map *map, t_data *data);
void	print_map(t_var *var);
void	put_xpm(char *file, t_data *data);
int		key_press(int keycode, t_var *var);
int		end_game(t_map *map, t_data *data);
int		move_player(int keycode, t_var *var);
int		move_up_w(t_map *map, t_data *data);
int		move_down_s(t_map *map, t_data *data);
int		move_left_a(t_map *map, t_data *data);
int		move_right_d(t_map *map, t_data *data);
void	player_death(t_map *map, t_data *data);
void	print_moves(t_data *data);
void	fire_state(t_data *data);
int		animated_fire(t_var *var);
void	put_xpm_fire(char *file, t_data *data);
void	set_player_pos(t_var *var);

#endif
