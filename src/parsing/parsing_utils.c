/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:58:00 by joapedro          #+#    #+#             */
/*   Updated: 2026/05/12 15:13:58 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	is_empty_line(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
		return (0);
		str++;
	}
	return (1);
}

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

void	check_duplicated(t_map *map, int identifier)
{
	if (identifier > 0)
		error_free_exit(DUPLICATED, map);
	map->type_identifiers++;
}

void	check_file_extension_xpm(char *path, t_map *map)
{
	char	*file_extension;
	int		len;

	file_extension = ft_strrchr(path, '/');
	file_extension++;
	file_extension = ft_strchr(file_extension, '.');
	if (!file_extension)
	{
		free(path);
		error_free_exit(MISSING_EXTENSION_XPM, map);
	}
	len = ft_strlen(file_extension);
	if ((ft_strncmp(file_extension, ".xpm", 4) != 0) && len == 4)
	{
		free(path);
		error_free_exit(WRONG_EXTENSION, map);
	}
}
