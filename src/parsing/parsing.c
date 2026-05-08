/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:03:15 by joapedro          #+#    #+#             */
/*   Updated: 2026/05/07 15:26:33 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//mapa so pode conter 6 carateres: 1,0,N,S,E,W
//tem de estar rodeado por paredes (1);
//separar config do mapa
//messagem de erro: "Error\n" seguida de mensagem informativa do erro
//parsing das texturas: verificar se o ficheiro existe, se pode ser aberto, se termina em .xpm (extensao)

void	check_duplicated(t_map *map, int identifier)
{
	if (identifier > 0)
	{	
		printf("Error\nDuplicated type identifier\n");
		exit(1);
	}
	map->type_identifiers++;
}

void	check_identifier(char *line, t_map *map)
{
	while (is_space(*line))
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0)
		check_duplicated(map, map->NO_identifier++);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		check_duplicated(map, map->SO_identifier++);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		check_duplicated(map, map->WE_identifier++);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		check_duplicated(map, map->EA_identifier++);
	else if (ft_strncmp(line, "F ", 2) == 0)
		check_duplicated(map, map->F_identifier++);
	else if (ft_strncmp(line, "C ", 2) == 0)
		check_duplicated(map, map->C_identifier++);
	else if (map->type_identifiers < 6)
	{
		printf("Error\nInvalid map configuration file\n"); // funcao para erro;
		exit(1);
	}
}

void	check_path_texture(char *line)
{
	while (!is_space(*line))
		line++;
	while (is_space(*line))
		line++;
	line = ft_strtrim(line, "\n");
	check_fd(line);
	check_file_extension_xpm(line);
	free (line);
}

void	check_if_valid_number(char *line)
{
	if (*line == '-' || *line == '+')
		line++;
	while (*line)
	{
		if (!ft_isdigit(*line))
		{
			printf("Error\nValues must be only numbers\n");
			exit(1);
		}
		line++;
	}
}

void	check_rgb_values(char *line)
{
	char	**rgb;
	int		value;
	int		i;

	while(ft_isalpha(*line) || is_space(*line))
		line++; // otimizar esta parte
	if (*line == '\0')
	{
		printf ("Error\nNo RGB values\n");
		exit(1);
	}
	line = ft_strtrim(line, "\n");
	rgb = ft_split(line, ',');
	free(line);
	i = 0;
	while (rgb[i])
	{
		check_if_valid_number(rgb[i]);
		value = ft_atoi(rgb[i]);
		if (value < 0 || value > 255)
		{
			printf("Error\nvalue must be between 0 and 255\n"); // criar funcao de erro
			free_array(rgb);
			exit(1);
		}
		i++;
	}
	if (i != 3)
	{
		printf("Error\nWrong RGB values format\n"); // criar funcao de erro
		free_array(rgb);
		exit(1);
	}
	free_array(rgb);
}

void	parsing_config(char *line, t_map *map)
{
	while (is_space(*line))
		line++;
	check_identifier(line, map);
	if (*line == 'F' || *line == 'C')
		check_rgb_values(line);
	else
		check_path_texture(line);
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
		if (map->type_identifiers < 6)
			parsing_config(map->map_array[i], map);
		i++;
	}
}
