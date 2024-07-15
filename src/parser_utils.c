/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:21:25 by rukoltso          #+#    #+#             */
/*   Updated: 2024/07/15 13:22:52 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int lines_in_file(char *file)
{
	int fd;
	char *line;
	int i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		exit(1);
	}
	i = 0;
	while (get_next_line(fd, &line))
		i++;
	return (i);
}