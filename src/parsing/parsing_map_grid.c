/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:40:58 by joapedro          #+#    #+#             */
/*   Updated: 2026/05/12 14:42:36 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_map_grid_array(t_map *map, int start)
{
	int	i;
	int	j;
	char	*line;

	i = start;
	while (map->map_array[i])
		i++;
	map->grid = ft_calloc((i - start) + 1, sizeof(char *));
	if(!map->grid)
		return (-1);
	j = 0;
	while (map->map_array[start])
	{
		line = ft_strtrim(map->map_array[start], "\n");
		map->grid[j] = ft_strdup(line);
		free(line);
		j++;
		start++;
	}
	map->grid[j] = NULL;
	return (start);
}

int	parsing_map_grid(t_map *map, int start)
{
	int	result;
	
	map->is_map = 1; // indicar que o map_grid comecou.
	result = fill_map_grid_array(map, start); // preencher grid e retornar quantas vezes o i andou.
	check_map_chars(map->grid, map);
	return (result);
}