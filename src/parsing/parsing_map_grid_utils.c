/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_grid_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:20:01 by joapedro          #+#    #+#             */
/*   Updated: 2026/05/13 13:08:14 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}


int	get_longest_line(t_map *map)
{
	int	i;
	int	max;
	int	len;
	
	max = 0;
	i = 0;
	while (map->grid[i])
	{
		len = ft_strlen(map->grid[i]);
		if (max < len)
			max = len;
		i++;
	}
	return (max);
}

int	get_map_height(t_map *map)
{
	int	i;

	i = 0;
	while(map->grid[i])
		i++;
	return (i);
}