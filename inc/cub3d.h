/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:48:31 by rukoltso          #+#    #+#             */
/*   Updated: 2024/07/15 14:19:15 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "../gnl/get_next_line.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_map
{
	char **map;
	char char_start;
	int width;
	int height;

}	t_map;

typedef struct s_player
{
	double x;
	double y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
	double move_speed;
	double rot_speed;
}	t_player;


//parser.c
void file_to_map(char *file, t_map *map);
int is_walled(t_map *map);
int is_map(char *file, t_map *map);

//parser_utils.c
int lines_in_file(char *file);

//print_error.c
void print_error(char *error);
