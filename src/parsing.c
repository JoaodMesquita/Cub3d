/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:03:15 by joapedro          #+#    #+#             */
/*   Updated: 2026/04/29 15:20:28 by joapedro         ###   ########.fr       */
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

void	parse_colors(char *str)
{
	printf("%s\n", str);
}
void	parse_texture_path(char *str)
{
/* 	int	i;

	i = 3; */
	printf("%s\n", str);
}

void	check_identifier(char *str)
{
	while (is_space(*str))
		str++;
	if (ft_strncmp(str, "NO ", 3) == 0 
	|| ft_strncmp(str, "SO ", 3) == 0
	|| ft_strncmp(str, "WE ", 3) == 0
	|| ft_strncmp(str, "EA ", 3) == 0)
		parse_texture_path(str);
	else if (ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
		parse_colors(str);
	else
		printf("ERROR!\n");
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

void	parse_config(t_map *map)
{
	int	i;
	
	i = 0;
	while(map->map_array[i])
	{
		if (is_empty_line(map->map_array[i]))
			i++;
		check_identifier(map->map_array[i]);
		i++;
	}
}

void	parsing(t_map *map)
{
	parse_config(map);
	//parse_map();
}