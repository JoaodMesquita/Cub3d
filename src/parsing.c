/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:03:15 by joapedro          #+#    #+#             */
/*   Updated: 2026/05/05 15:42:24 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

//mapa so pode conter 6 carateres: 1,0,N,S,E,W
//tem de estar rodeado por paredes (1);
//separar config do mapa
//messagem de erro: "Error\n" seguida de mensagem informativa do erro

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
int	is_map(char *line)
{
	while(*line)
	{
		if (*line != ' ' 
		|| *line != '0'
		|| *line != '1'
		|| *line != 'N'
		|| *line != 'S'
		|| *line != 'W'
		|| *line != 'E')
			return (0);
		line++;
	}
	return (1);
}	

void	parsing_config(char *line, t_map *map)
{
	while (is_space(*line))
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		map->NO_indentifier = 1;
		printf("ok\n");
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		map->SO_indentifier = 1;
		printf("ok\n");
	}	
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		map->WE_indentifier = 1;
		printf("ok\n");
	}	
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		map->EA_indentifier = 1;
		printf("ok\n");
	}
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		map->F_indentifier = 1;
		printf("ok\n");
	}	
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		map->C_indentifier = 1;
		printf("ok\n");
	}	
	else
		
}

void	parsing(t_map *map)
{
	int	i;
	
	i = 0;
	while(map->map_array[i])
	{
		if (is_empty_line(map->map_array[i]))
		{
			i++;
			continue;
		}
		parsing_config(map->map_array[i], map);
		i++;
	}
}
