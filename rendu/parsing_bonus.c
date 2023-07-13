/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:15:47 by rahmed            #+#    #+#             */
/*   Updated: 2021/12/22 20:48:42 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_errors(size_t err, t_map *map)
{
	ft_printf("Error\n");
	if (err == ERR_ARGS)
		ft_printf("ARGS : Format must be ./so_long <filename>.ber\n");
	else if (err == ERR_FILENAME_FORMAT)
		ft_printf("FILE : Format must be <filename>.ber\n");
	else if (err == ERR_OPEN_FILE)
		ft_printf("FILE : can't open your file\n");
	else if (err == ERR_MALLOC)
		ft_printf("MEMORY : error on MALLOC\n");
	else if (err == ERR_MAP_WALLS)
		printf("MAP : Surrounding walls must be closed error at Line[%lu]\n", \
		map->height + 1);
	else if (err == ERR_MAP_DATA)
		printf("MAP : Wrong MAP data composition error at Line[%lu]-Col[%lu]\n", \
		map->height + 1, map->width + 1);
	else if (err == ERR_MAP_SIZE)
		printf("MAP : Must be rectangular error at Line[%lu]\n", \
		map->height + 1);
	else if (err == ERR_MAP_COMPOSITION)
		printf("MAP : Bad MAP file composition %luP/1P - %luE/1E(Min)" \
		"- %luC/1C(Min)\n", map->nbplayer, map->nbexit, map->nbcollectible);
	else if (err == ERR_SIZE_BLOCK)
		printf("MAP : Block size must be %dx%d\n", SIZE_BLOCK, SIZE_BLOCK);
	exit(EXIT_FAILURE);
}

void	read_map_lines(char *filename, t_map *map)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	size_t	len;

	map->maxline = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		check_errors(ERR_OPEN_FILE, NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		len = 0;
		while (buffer[len])
		{
			if (buffer[len] == '\n')
				++map->maxline;
			++len;
		}
		if (buffer[len] == '\0')
			++map->maxline;
	}
	close(fd);
}

void	check_file_ext(char *filename)
{
	char	*ext;

	ext = ".ber";
	while ((*filename != '.') && *filename)
		++filename;
	while (*ext)
	{
		if (*filename == *ext)
		{
			++filename;
			++ext;
		}
		else
			check_errors(ERR_FILENAME_FORMAT, NULL);
	}
	if (*filename)
		check_errors(ERR_FILENAME_FORMAT, NULL);
}

void	read_map_data(char *filename, t_map *map)
{
	int		fd;
	size_t	nbline;

	nbline = 0;
	read_map_lines(filename, map);
	map->data = ft_calloc((map->maxline + 1), sizeof(filename));
	if (!map->data)
	{
		free(map->data);
		check_errors(ERR_MALLOC, NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		check_errors(ERR_OPEN_FILE, NULL);
	while (nbline < map->maxline + 1)
	{
		map->data[nbline] = ft_get_next_line(fd);
		++nbline;
	}
	close(fd);
}
