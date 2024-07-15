/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:51:11 by rukoltso          #+#    #+#             */
/*   Updated: 2024/07/15 14:21:41 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void file_to_map(char *file, t_map *map)
{
	int fd;
	char *line;
	int i;
	int j;
	int lines;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("File not found");
	lines = lines_in_file(file);
	close(fd);
	map->map = malloc(sizeof(char *) * lines);
	if (map->map == NULL)
		print_error("Malloc error");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("File not found");
	i = 0;
	while (line = get_next_line(fd))
	{
		if (!line)
			print_error("Malloc error");
		map->map[i] = ft_strdup(line);
        if (map->map[i] == NULL)
            print_error("Malloc error");
        if (i == 0)
            map->width = ft_strlen(line);
        else if (ft_strlen(line) != map->width)
            print_error("All lines must be the same length");
		free(line);
        i++;
	}
	map->height = i;
	close(fd);
}

int is_walled(t_map *map)
{
	int i;
	int j;

	j = 0;
	while (j < map->width)
	{
		if (map->map[0][j] != '1' || map->map[map->height - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int is_map(char *file, t_map *map)
{
	int i;
	int j;
	int spawn_found;

	file_to_map(file, map);
	if (!is_walled(map))
		return (0);
	i = 0;
	spawn_found = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || map->map[i][j] == 'E' || map->map[i][j] == 'W')
                spawn_found++;
		}
	}
	if (spawn_found != 1)
		return (0);
	return (1);
}

/*
111111
100001
100001
100N01
111111
*/
