/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:47:54 by rukoltso          #+#    #+#             */
/*   Updated: 2024/07/15 14:19:38 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void free_map(t_map *map)
{
    int i;

    for (i = 0; i < map->height; i++)
        free(map->map[i]);
    free(map->map);
}

int main(int ac, char **av)
{
    t_map map;

    if (ac != 2)
    {
        printf("Usage: %s <map_file>\n", av[0]);
        return 1;
    }
    if (is_map(av[1], &map))
        printf("The map is valid.\n");
    else
        printf("The map is not valid.\n");
	
	free_map(&map);
    return 0;
}