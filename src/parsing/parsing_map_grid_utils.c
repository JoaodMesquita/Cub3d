/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_grid_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:20:01 by joapedro          #+#    #+#             */
/*   Updated: 2026/05/12 15:20:50 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void	check_map_chars(char **map_grid, t_map *map)
{
	char	*valid_chars;
	int		i;
	int		j;
	
	valid_chars = " 01NSWE";
	i = 0;
	while(map_grid[i])
	{
		j = 0;
		while (map_grid[i][j])
		{
			if(!ft_strchr(valid_chars, map_grid[i][j]))
				error_free_exit(INVALID_CHAR,map);
			if(is_player(map_grid[i][j]))
				map->player_count++;
			j++;
		}
		i++;
	}
	if (map->player_count > 1)
		error_free_exit(DUPLICATE_PLAYER,map);
}